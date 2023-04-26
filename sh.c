#include "sh.h"


int main(void)
{
	char *buffer = 0;
        char **args;
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
			 exit(EXIT_FAILURE);
		}
		else if (c_reads > 0 && buffer[c_reads - 1] == '\n')
		{
			buffer[c_reads - 1] = '\0';
		}
		args = malloc(sizeof(char *) * 2);
		if (args == NULL)
		{
			perror("Errror malloc");
			 exit(EXIT_FAILURE);
		}
		args[0] = buffer;
		args[1] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("Error fork");
			 exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error execve");
				 exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("Error wait");
				 exit(EXIT_FAILURE);
			}	
		}
		free(args);
		
	}
	free(buffer);
	return (0);
}
