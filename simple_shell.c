#include "simple_shell.h"

/**
 * main - the main function.
 * @argc: number of arguments.
 * @argv: array of strings.
 * @env: environment variables.
 *
 * Return: 0 on success.-1 otherwise.
 */

int main(int argc, char **argv, char **env)
{
	char **args;
	char *buf;
	char *buf_copy;
	unsigned int len_args;
	(void)argc;

	while (1)
	{
		_putchar('$');
		buf = read_line();
		if (*buf == '\n')
			continue;
		buf_copy = _strdup(buf);
		len_args = get_num_tokens(buf);
		args = malloc(sizeof(char *) * (len_args + 1));
		if (args == NULL)
		{
			perror("malloc fails ");
			return (-1);
		}
		args = fill_arr_by_tokens(buf_copy, args);
		if (args == NULL)
			return (-1);
		if (_strcmp(args[0], "exit") == 0)
		{
			free(buf);
			free(buf_copy);
			is_input_exit(args);
		}
		if (execute_cmd(args, argv, env))
		{
			free_arr_of_strs(args);
			free(buf);
			free(buf_copy);
			continue;
		}
	}
	return (0);
}
