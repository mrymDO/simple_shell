#include "simple_shell.h"

/**
 * free_all - free memory.
 * @args: array of strings.
 * @buf1: free buffer1.
 * @buf2: free buffer2.
 * @buf3: free buffer3.
 *
 * Return: void.
 */

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
/**
 * handle_sig - handle signal
 * @sig: signal.
 *
 * Return: void.
 */

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
 * Return: 0 always success. -1 otherwise.
 */

int main(int argc, char **argv, char **env)
{
	char *buf1, *buf2, *buf3, **args;
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
		buf1 = NULL;

		buf1 = read_line();
		if (*buf1 == '\0')
			continue;
		buf2 = _strdup(buf1);
		buf3 = _strdup(buf2);
		len_args = get_num_tokens(buf1);

		args = malloc(sizeof(char *) * (len_args + 1));
		if (args == NULL)
		{
			perror("malloc fails ");
			return (-1);
		}
		args = fill_arr_by_tokens(buf2, args);
		if (args[0] == NULL)
			continue;
		execute_cmd(args, argv, env, atty, buf1, buf2, buf3);

		free_all(args, buf1, buf2, buf3);
	}
	return (0);
}
