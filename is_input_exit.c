#include "simple_shell.h"

/**
 * is_input_exit - check if input equal to exit.
 * @args: users's input.
 *
 * Return: 1 on success. 0 otherwise.
 */

int is_input_exit(char **args)
{
	int i = 0, len = 0;

	while (args[i++])
		len++;

	if (strcmp(args[0], "exit") == 0 && len == 1)
		return (1);
	return (0);
}
