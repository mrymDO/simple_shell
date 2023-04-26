#include "simple_shell.h"

/**
 * is_input_exit - checks if the command is built-in command 'exit'
 * @args: arguments
 * Return: 0 if it is not 'exit'. Else 1
 */
void is_input_exit(char **args)
{
	int i = 0, len = 0, status = 0;

	while (args[i++])
		len++;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (len == 1)
			exit(status);
		if (args[1] != NULL && len == 2)
		{
			status = _atoi(args[1]);
			exit(status);
		}
	}
}
