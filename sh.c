#include "sh.h"


int main(void)
{
	char *buffer = NULL, **args;
	size_t len = 0;
	ssize_t c_reads;
	pid_t pid;
	int status;
	int is_atty = 0;

	while(1 && is_atty == 0)
	{
		if (isatty(STDIN_FILENO) == 0)
			is_atty = 1;
		else
			write(1, "$ ", 2);
		fflush(stdout);
		c_reads = getline(&buffer, &len, stdin);
		if (c_reads == -1)
		{
			write(1, "\n", 1);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		if (c_reads > 0 && buffer[c_reads - 1] == '\n')
		{
			buffer[c_reads - 1] = '\0';
			args = malloc(sizeof(char *) * 2);
			args[0] = buffer;
		args[1] = NULL;
		pid = fork();
		if (pid < 0)
		{
			perror("Error fork");
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error execve");
			}
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("Error wait");
			}
		}
                free(args);
		}
	}
	free(buffer);
	return (0);
}
