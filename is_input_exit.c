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

	if (len == 1)
		_exit(status);
	if (len == 2)
	{
		status = _atoi(args[1]);
		_exit(status);
	}
}
