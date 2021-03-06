#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>


static void child()
{
	char *args[] = { "/bin/echo", "Hello", NULL};
	printf("I'm child! my pid is %d.\n", getpid());
	fflush(stdout);

	execve("/bin/echo", args, NULL);
	exit( EXIT_SUCCESS);
}

static void parent (pid_t pic_c)
{
	printf("I'm parent pid is %d and the pid of my child is %d\n", getpid(), pic_c);
	exit(EXIT_SUCCESS);
}

int main(void)
{
	pid_t ret;
	ret = fork();
	if(ret == -1)
		err(EXIT_FAILURE, "fork() faild");
	if(ret == 0)
	{
		child();
	}
	else
	{
		parent(ret);
	}

	err(EXIT_FAILURE, "sholdn't reach here");
}

