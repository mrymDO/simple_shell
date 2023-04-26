#include "sh.h"


int main(void)
{
	char *buffer, **args;
	size_t len = 0;
	ssize_t c_reads;
	pid_t pid;
	int status;

	while(1)
	{
		write(1, "$ ", 2);
		fflush(stdout);
		c_reads = getline(&buffer, &len, stdin);
		if (c_reads == -1)
		{
			free(buffer);
			perror("Error getline");
		}
		if (c_reads > 0 && buffer[c_reads - 1] == '\n')
			buffer[c_reads - 1] = '\0';
		args = malloc(sizeof(char *) * 2);
		args[0] = malloc(sizeof(char) * (strlen(buffer) + 1));
		args[1] = NULL;
		strcpy(args[0], buffer);
		pid = fork();
		if (pid == -1)
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
			free(buffer);
			free(args[0]);
            		free(args);
		}
	}
	return (0);
}
