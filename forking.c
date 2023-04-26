#include "simple_shell.h"

/**
 * forking - create and execute command in child process.
 * @args: the command and its arguments to be executed int the chils process
 * Return : void
 */

void forking(char *args[], char **env)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(args[0], args, env);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("Wait error");
		}
	}
}
