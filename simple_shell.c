#include "simple_shell.h"


void free_all(char **args, char *buf1, char *buf2, char *buf3)
{
	if (args)
		free_arr_of_strs(args);
	if (buf1)
		free(buf1);
	if (buf2)
		free(buf2);
	if (buf3)
		free(buf3);
}
void handle_sig(int sig)
{
	(void)sig;
	write(1, "\n$ ", 3);
}
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

	signal(SIGINT, handle_sig);
	while (1 && atty == 0)
	{
		if (isatty(STDIN_FILENO) == 0)
			atty = 1;
		else
			write(1, "$ ", 2);
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
		execute_cmd(args, argv, env, atty, buf_copy_copy);

		free_all(args, buf, buf_copy, buf_copy_copy);
	}
	return (0);
}
