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
	char *buf_copy_copy;
	unsigned int len_args;
	int atty = 0;

	(void)argc;

	while (1 && atty == 0)
	{
		if (isatty(STDIN_FILENO) == 0)
			atty = 1;
		else
			_putchar('$');
		fflush(stdout);
		buf = NULL;
			
		buf = read_line();
		if (*buf == '\n')
			continue;
		buf_copy = _strdup(buf);
		buf_copy_copy = _strdup(buf);
		len_args = get_num_tokens(buf);

		args = malloc(sizeof(char *) * (len_args + 1));
		if (args == NULL)
		{
			perror("malloc fails ");
			return (-1);
		}
		args = fill_arr_by_tokens(buf_copy, args);
		if (execute_cmd(args, argv, env, atty, buf_copy_copy))
			continue;
		free_arr_of_strs(args);
		free(buf);
		free(buf_copy);
		free(buf_copy_copy);
	}
	return (0);
}
