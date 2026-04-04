#include <u.h>
#include <libc.h>
#include <thread.h>

typedef struct Exec Exec;

struct Exec {
	/* these two specify what program (and arguments) to run using procexec */
	char *file;
	char **argv;

	/* this will have either -1 or the actual pid of the executed program sent over */
	Channel *pid;
};

void
pexec(void *args)
{
	Exec *e = args;
	procexec(e->pid, e->file, e->argv);
}

void
threadmain(int, char **)
{
	Exec e;
	int i, n, pid;
	Channel *waitc;
	Waitmsg *w;
	char *argv[] = {"rc", "-c", "sleep 2", nil};

	quotefmtinstall();

	/* this HAS to be called before spawning other threads
	 * otherwise those threads won't send their status
	 */
	waitc = threadwaitchan();

	/* that's where we get the pid from */
	e.pid = chancreate(sizeof(int), 0);

	for(n = i = 0; i < 3; n++, i++){
		/* last process always fails to demonstrate the error status */
		if(i == 2)
			argv[2] = "this breaks";
		e.file = "/bin/rc";
		e.argv = argv;
		proccreate(pexec, &e, 4096);

		/* receive the pid */
		recv(e.pid, &pid);
		if(pid < 0)
			sysfatal("procexec failed");

		fprint(2, "pid %d running\n", pid);
	}

	/* won't get any new pids at this point */
	chanfree(e.pid);

	/* wait until all processes are finished
	 * we know how many there are so it's pretty easy
	 */
	while(n > 0){
		/* w (Waitmsg) points to the result of a finished process */
		w = recvp(waitc);
		fprint(2, "pid %d: %q\n", w->pid, w->msg);
		/* each one of them is allocated with malloc */
		free(w);
		n--;
	}

	threadexitsall(nil);
}
