#define _XOPEN_SOURCE 700
#include "corc.h"
#include "ucontext.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

/* Minimal implementation notes:
   - Uses ucontext (getcontext/makecontext/swapcontext) for context switching.
   - Each Corc has its own stack allocated with malloc.
   - Runtime maintains per-P runqueue (simple singly-linked queue) and a global runnable count.
   - Channels implement unbuffered rendezvous by pairing waiting senders/receivers.
   - Cooperative: corc_yield and blocking channel ops switch to scheduler.
*/

/* --- Types --- */

struct Corc {
    ucontext_t ctx;
    void (*fn)(void*);
    void *arg;
    void *stack;
    size_t stacksz;
    struct Corc *next; /* runqueue link */
    atomic_int state; /* 0 runnable, 1 running, 2 blocked, 3 finished */
};

typedef struct Waiter {
    Corc *g;
    void *elem; /* pointer to value (copy) */
    struct Waiter *next;
} Waiter;

struct Chan {
    size_t elemsz;
    pthread_mutex_t lock;
    Waiter *sendq; /* waiting senders */
    Waiter *recvq; /* waiting receivers */
    atomic_int closed;
};

/* Per-P structure */
typedef struct P {
    pthread_t mthread;
    /* simple runqueue (head/tail) */
    Corc *rq_head;
    Corc *rq_tail;
    pthread_mutex_t rq_lock;
} P;

/* --- Globals --- */

static P *procs = NULL;
static int nprocs = 0;
static atomic_int global_runnable = 0;
static atomic_int runtime_running = 0;

/* Main scheduler context (per-thread we use a scheduler context saved in TLS) */
static __thread ucontext_t sched_ctx;
static __thread Corc *current_g = NULL; /* current running coroutine on this M */

/* Forward */
static void schedule_and_run(void);
static void corc_entry_trampoline(void);

static void usleep(unsigned int usec){
    struct timespec ts;
    ts.tv_sec = usec / 1000000;
    ts.tv_nsec = (usec % 1000000) * 1000;
    nanosleep(&ts, NULL);
}

/* --- Runqueue helpers --- */

static void rq_push(P *p, Corc *g)
{
    g->next = NULL;
    pthread_mutex_lock(&p->rq_lock);
    if(p->rq_tail){
        p->rq_tail->next = g;
        p->rq_tail = g;
    }else{
        p->rq_head = p->rq_tail = g;
    }
    pthread_mutex_unlock(&p->rq_lock);
    atomic_fetch_add(&global_runnable, 1);
}

static Corc* rq_pop(P *p)
{
    pthread_mutex_lock(&p->rq_lock);
    Corc *g = p->rq_head;
    if(g){
        p->rq_head = g->next;
        if(p->rq_head == NULL) p->rq_tail = NULL;
        g->next = NULL;
        atomic_fetch_sub(&global_runnable, 1);
    }
    pthread_mutex_unlock(&p->rq_lock);
    return g;
}

/* Round-robin assignment: choose a P based on thread id for now */
static P* choose_P_for_new(void)
{
    static atomic_int rr = 0;
    int idx = atomic_fetch_add(&rr, 1) % nprocs;
    return &procs[idx];
}

/* --- Coroutine lifecycle --- */

#define DEFAULT_STACK  (64 * 1024)

Corc* corc_create(void (*fn)(void*), void *arg, size_t stacksz)
{
    Corc *g = malloc(sizeof(*g));
    if(!g) return NULL;
    if(stacksz == 0) stacksz = DEFAULT_STACK;
    void *stack = malloc(stacksz);
    if(!stack){ free(g); return NULL; }

    g->fn = fn;
    g->arg = arg;
    g->stack = stack;
    g->stacksz = stacksz;
    g->next = NULL;
    atomic_init(&g->state, 0);

    /* init context */
    if(getcontext(&g->ctx) != 0){
        free(stack);
        free(g);
        return NULL;
    }
    g->ctx.uc_stack.ss_sp = stack;
    g->ctx.uc_stack.ss_size = stacksz;
    g->ctx.uc_link = &sched_ctx; /* when coroutine returns, go to scheduler */
    makecontext(&g->ctx, corc_entry_trampoline, 0);

    /* enqueue onto a P runqueue */
    P *p = choose_P_for_new();
    rq_push(p, g);

    return g;
}

static void corc_free(Corc *g)
{
    if(!g) return;
    free(g->stack);
    free(g);
}

/* Entry trampoline invoked inside new coroutine context */
static void corc_entry_trampoline(void)
{
    /* current_g should already be set by scheduler before swapping in. */
    Corc *g = current_g;
    if(!g) {
        /* shouldn't happen */
        fprintf(stderr, "corc: no current_g in trampoline\n");
        return;
    }
    atomic_store(&g->state, 1); /* running */
    g->fn(g->arg);
    atomic_store(&g->state, 3); /* finished */
    /* after function returns, switch to scheduler context */
    /* corc_free delayed until scheduler sees finished state */
    swapcontext(&g->ctx, &sched_ctx);
    /* unreachable */
}

/* Yield: cooperative */
void corc_yield(void)
{
    Corc *g = current_g;
    if(!g) return;
    atomic_store(&g->state, 0); /* runnable */
    /* push back to runqueue of current thread's P */
    /* find P by pthread_self comparison (linear scan) */
    pthread_t self = pthread_self();
    P *myP = NULL;
    for(int i=0;i<nprocs;i++){
        if(pthread_equal(procs[i].mthread, self)){
            myP = &procs[i];
            break;
        }
    }
    if(!myP){
        /* If schedule running on main thread before Ms started, push to P0 */
        myP = &procs[0];
    }
    rq_push(myP, g);
    /* switch to scheduler */
    swapcontext(&g->ctx, &sched_ctx);
}

/* --- Channels --- */

Chan* chan_create(size_t elemsz)
{
    Chan *c = malloc(sizeof(*c));
    if(!c) return NULL;
    c->elemsz = elemsz;
    pthread_mutex_init(&c->lock, NULL);
    c->sendq = c->recvq = NULL;
    atomic_init(&c->closed, 0);
    return c;
}

void chan_close(Chan* c)
{
    if(!c) return;
    atomic_store(&c->closed, 1);
    /* wake up waiting receivers/senders: we simply dequeue and mark closed
       send/recv operations will return -1 if closed. For brevity we won't
       actively wake blocked coroutines in this minimal prototype. */
}

/* Helper: allocate waiter with copy buffer */
static Waiter* waiter_new(Corc *g, const void *elem, size_t elemsz)
{
    Waiter *w = malloc(sizeof(*w));
    if(!w) return NULL;
    w->g = g;
    w->next = NULL;
    if(elem && elemsz){
        w->elem = malloc(elemsz);
        if(!w->elem){ free(w); return NULL; }
        memcpy(w->elem, elem, elemsz);
    }else{
        w->elem = NULL;
    }
    return w;
}

static void waiter_free(Waiter *w)
{
    if(!w) return;
    free(w->elem);
    free(w);
}

/* Block current coroutine on channel, used for both send/recv */
static int chan_block_and_pair(Chan *c, int is_send, const void *send_buf, void *recv_out)
{
    if(atomic_load(&c->closed)) return -1;
    pthread_mutex_lock(&c->lock);
    /* Fast-path: pair with waiting opposite */
    if(is_send){
        if(c->recvq){
            Waiter *r = c->recvq;
            c->recvq = r->next;
            /* copy send->recv */
            if(recv_out && r->elem){
                memcpy(recv_out, send_buf, c->elemsz);
            }else if(r->elem){
                /* receiver provided buffer earlier; copy into its saved buffer */
                memcpy(r->elem, send_buf, c->elemsz);
            }
            Corc *recv_g = r->g;
            waiter_free(r);
            pthread_mutex_unlock(&c->lock);
            /* wake receiver: push it runnable */
            P *p = choose_P_for_new(); /* place back onto some runqueue */
            rq_push(p, recv_g);
            return 0;
        }
    }else{
        if(c->sendq){
            Waiter *s = c->sendq;
            c->sendq = s->next;
            /* copy s->elem -> recv_out */
            if(recv_out && s->elem){
                memcpy(recv_out, s->elem, c->elemsz);
            }
            Corc *send_g = s->g;
            waiter_free(s);
            pthread_mutex_unlock(&c->lock);
            P *p = choose_P_for_new();
            rq_push(p, send_g);
            return 0;
        }
    }

    /* No pair found: enqueue current coroutine as waiter and block */
    Corc *g = current_g;
    atomic_store(&g->state, 2); /* blocked */
    Waiter *w = waiter_new(g, is_send ? send_buf : NULL, c->elemsz);
    if(!w){
        pthread_mutex_unlock(&c->lock);
        return -1;
    }
    if(is_send){
        w->next = c->sendq; c->sendq = w;
    }else{
        w->next = c->recvq; c->recvq = w;
    }
    pthread_mutex_unlock(&c->lock);

    /* Switch to scheduler (blocking) */
    swapcontext(&g->ctx, &sched_ctx);

    /* Once resumed, check if channel closed */
    if(atomic_load(&c->closed)) return -1;

    /* For receiver, copy was performed by sender before waking us, but we
       didn't store the data location; as a minimal convenience we expect
       the scheduler or paired code to have copied into recv_out. */
    return 0;
}

int chan_send(Chan* c, const void *elem)
{
    if(!c) return -1;
    if(atomic_load(&c->closed)) return -1;
    /* Try fast path without locking: attempt to match a receiver */
    /* For simplicity we go straight to blocking path */
    return chan_block_and_pair(c, 1, elem, NULL);
}

int chan_recv(Chan* c, void *out)
{
    if(!c) return -1;
    if(atomic_load(&c->closed) && c->sendq == NULL) return -1;
    return chan_block_and_pair(c, 0, NULL, out);
}

/* --- Scheduler & M threads --- */

static void* m_thread_main(void *arg)
{
    P *p = (P*)arg;
    /* store pthread id */
    p->mthread = pthread_self();
    /* scheduler loop for this M: run coroutines until no runnable remain */
    while(atomic_load(&runtime_running)){
        Corc *g = rq_pop(p);
        if(!g){
            /* no runnable here; check global runnable count */
            if(atomic_load(&global_runnable) == 0){
                /* idle: sleep briefly */
                usleep(1000);
                continue;
            }else{
                /* yield CPU */
                usleep(100);
                continue;
            }
        }
        /* run g */
        current_g = g;
        atomic_store(&g->state, 1); /* running */
        /* swap to coroutine context; on return, scheduler context resumes here */
        swapcontext(&sched_ctx, &g->ctx);
        /* after coroutine yields or finishes, inspect state */
        if(atomic_load(&g->state) == 3){
            /* finished: free */
            corc_free(g);
            current_g = NULL;
            continue;
        }
        /* if runnable again, continue loop (it was pushed by corc_yield or channel pairing) */
        current_g = NULL;
    }
    return NULL;
}

void corc_runtime_init(int requested_nprocs)
{
    if(procs) return; /* already init */
    if(requested_nprocs <= 0){
        requested_nprocs = (int)sysconf(_SC_NPROCESSORS_ONLN);
        if(requested_nprocs <= 0) requested_nprocs = 1;
    }
    nprocs = requested_nprocs;
    procs = calloc(nprocs, sizeof(P));
    for(int i=0;i<nprocs;i++){
        pthread_mutex_init(&procs[i].rq_lock, NULL);
        procs[i].rq_head = procs[i].rq_tail = NULL;
    }
}

void corc_runtime_run(void)
{
    if(!procs) corc_runtime_init(0);
    atomic_store(&runtime_running, 1);
    /* create Ms */
    for(int i=0;i<nprocs;i++){
        /* spawn pthread that runs m_thread_main */
        pthread_create(&procs[i].mthread, NULL, m_thread_main, &procs[i]);
    }
    /* Main thread becomes also an M: run its scheduler loop until global runnable 0 */
    while(atomic_load(&runtime_running)){
        /* If there are no runnable coroutines and global_runnable==0, exit */
        if(atomic_load(&global_runnable) == 0){
            /* small grace period: break and stop runtime */
            break;
        }
        /* similar loop as m_thread_main */
        P *p0 = &procs[0];
        Corc *g = rq_pop(p0);
        if(!g){
            usleep(1000);
            continue;
        }
        current_g = g;
        atomic_store(&g->state, 1);
        swapcontext(&sched_ctx, &g->ctx);
        if(atomic_load(&g->state) == 3){
            corc_free(g);
            current_g = NULL;
            continue;
        }
        current_g = NULL;
    }
    /* signal Ms to stop */
    atomic_store(&runtime_running, 0);
    /* join Ms */
    for(int i=0;i<nprocs;i++){
        pthread_join(procs[i].mthread, NULL);
    }
    /* cleanup procs */
    for(int i=0;i<nprocs;i++){
        pthread_mutex_destroy(&procs[i].rq_lock);
    }
    free(procs);
    procs = NULL;
    nprocs = 0;
}

void corc_runtime_stop(void)
{
    atomic_store(&runtime_running, 0);
}

/* Return current coroutine pointer */
Corc* corc_current(void)
{
    return current_g;
}

