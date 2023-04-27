#include "simple_shell.h"

/**
 * is_input_exit - checks if the command is built-in command 'exit'
 * @args: arguments
 * @buf1: buffer1
 * @buf2: buffer2
 * @buf3: buffer3
 * Return: void.
 */
void is_input_exit(char **args, char *buf1, char *buf2, char *buf3)
{
	int i = 0, len = 0, status = 0;

	while (args[i])
	{
		len++;
		i++;
	}

	if (len == 1 || (len == 2 && _strcmp(args[1], "0") == 0))
	{
		free_all(args, buf1, buf2, buf3);
		exit(status);
	}
	if (len == 2)
	{
		status = _atoi(args[1]);
		free_all(args, buf1, buf2, buf3);
		exit(status);
	}
}
