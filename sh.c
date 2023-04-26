#include "sh.h"

/*void ignore_signal(int signal)
{
    (void) signal;
    write(STDOUT_FILENO, "\n$ ", 3);
    fflush(stdout);
}
*/

void forking(char **args, char **env, char *name, int is_atty, char *buffer)
{
	int status;
	pid_t pid = fork();

                if (pid == -1)
                {
                        perror("Error fork");
                }
                else if (pid == 0)
                {
                        if (execve(args[0], args, env) == -1)
                        {
				if (is_atty)
				fprintf(stderr, "%s : %d: %s: not found\n", name, 1, args[0]);
				else
					perror(name);
                        }
                }
                else
                {
                        if (wait(&status) == -1)
                        {
                                perror("Error wait");
                        }
			free(args);
			free(buffer);
                }
}

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, **args;
	size_t len = 0;
	ssize_t c_reads;
	int is_atty = 0;

	if (argc > 2)
		return (-1);

	/*signal(SIGINT, ignore_signal);*/
	while(1 && is_atty == 0)
	{
		if (isatty(STDIN_FILENO) == 0)
			is_atty = 1;
		else
			write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
		c_reads = getline(&buffer, &len, stdin);
		if (c_reads == -1)
		{
		printf("adas");
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
		{
			free(buffer);
			return (-1);
		}

		args[0] = buffer;
		args[1] = NULL;
		forking(args, env, argv[0], is_atty, buffer);
	}
	return (0);
}
