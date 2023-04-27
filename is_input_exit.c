#include "simple_shell.h"

/**
 * is_input_exit - checks if the command is built-in command 'exit'
 * @args: arguments
 * @argv: command's arguments
 * @buf1: buffer1
 * @buf2: buffer2
 * @buf3: buffer3
 * Return: void.
 */
void is_input_exit(char **args, char **argv,
		char *buf1, char *buf2, char *buf3)
{
	int i = 0, len = 0, status = 0;

	while (args[i])
	{
		len++;
		i++;
	}

	if (len == 1)
	{
		free_all(args, buf1, buf2, buf3);
		exit(status);
	}
	if (len == 2)
	{
		for (i = 0; args[1][i]; i++)
		{
			if (args[1][i] < '0' || args[1][i] > '9' || args[1][i] != '+')
			{
				fprintf(stderr, "%s : %d: %s: Illegal number: %s\n",
						argv[0], 1, args[0], args[1]);
				free_all(args, buf1, buf2, buf3);
				exit(EXIT_FAILURE);
			}
		}
		status = _atoi(args[1]);
		free_all(args, buf1, buf2, buf3);
		exit(status);
	}
}
