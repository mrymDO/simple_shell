#include "sh.h"

void ignore_signal(int signal)
{
    (void) signal;
    write(STDOUT_FILENO, "\n$ ", 3);
    fflush(stdout);
}

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, **args;
	size_t len = 0;
	ssize_t c_reads;
	pid_t pid;
	int status;
	int is_atty = 0;

	(void) argc;
	signal(SIGINT, ignore_signal);
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
			buffer[c_reads - 1] = '\0';
		if (*buffer == '\0')
			continue;
		args = malloc(sizeof(char *) * 2);
		if (args == NULL)
			return (-1);
		args[0] = malloc(sizeof(char) * (_strlen(buffer) + 1));
		if (args[0] == NULL)
		{
			free(args);
			return(-1);
		}
		_strcpy(args[0], buffer);
		args[1] = NULL;
	
		pid = fork();
		if (pid < 0)
		{
			perror("Error fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			if (execve(args[0], args, env) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
	
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error wait");
			exit(EXIT_FAILURE);
		}
                free(args[0]);
		free(args);
	}
	free(buffer);
	return (0);
}
