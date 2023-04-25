#include "simple_shell.h"

/**
 * is_input_exit - check if user entered exit cmd.
 * @args: array of strings.
 *
 * Return: void.
 */

void is_input_exit(char **args)
{
	int i = 0, len = 0, status = 0;

	while (args[i++])
		len++;

	if (len == 1)
	{
		free_arr_of_strs(args);
		exit(status);
	}
	if (args[1] != NULL && len == 2)
	{
		free_arr_of_strs(args);
		status = atoi(args[1]);
		exit(status);
	}
}
