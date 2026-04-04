#ifndef CORC_H
#define CORC_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Corc Corc;     /* coroutine handle (G) */
typedef struct Chan Chan;     /* channel */

/* Initialize runtime. nprocs==0 -> detect CPU count. Call once in main. */
void corc_runtime_init(int nprocs);

/* Create a coroutine running fn(arg). stacksz bytes (0 -> default). */
Corc* corc_create(void (*fn)(void*), void *arg, size_t stacksz);

/* Yield current coroutine cooperatively. */
void corc_yield(void);

/* Start runtime: spawn Ms (pthread) and run until all coroutines exit.
   This blocks until runtime_stop is called or no runnable coroutines remain. */
void corc_runtime_run(void);

/* Stop runtime (request all Ms to exit). */
void corc_runtime_stop(void);

/* Channel (unbuffered rendezvous) */
Chan* chan_create(size_t elemsz);
void chan_close(Chan* c); /* close channel */
int chan_send(Chan* c, const void *elem); /* blocks; returns 0 on success, -1 if closed */
int chan_recv(Chan* c, void *out);        /* blocks; returns 0 on success, -1 if closed */

/* Utility: current coroutine pointer (nullable) */
Corc* corc_current(void);

#ifdef __cplusplus
}
#endif

#endif /* CORC_H */
