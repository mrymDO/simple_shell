#include "simple_shell.h"

/**
 * forking - create and execute command in child process
 * @args: the command and its arguments to be executed int the chils process
 * Return : void
 */

void forking(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		return;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve error");
			return;
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait error");
			return;
		}
	}
}
