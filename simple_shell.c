#include "simple_shell.h"

/**
 * main - the main function.
 * @argc: number of arguments.
 * @argv: array of strings.
 * @env: environment variables.
 *
 * Return: 0 always success.
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
		buf = NULL;

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
		if (check_for_comts(args))
			args = check_for_comts(args);
		if (execute_cmd(args, argv, env))
			continue;
		free_arr_of_strs(args);
		free(buf_copy);
		free(buf);
	}
	return (0);
}
