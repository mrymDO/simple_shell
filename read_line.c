#include "simple_shell.h"

/**
 * read_line - read user's input.
 *
 * Return: the buffer entered by user.
 */

char *read_line()
{
	ssize_t chars_read = 0;
	size_t len = 0;
	char *buf = NULL;

	chars_read = getline(&buf, &len, stdin);
	if (chars_read == -1)
	{
		write(1, "exit", 4);
		free(buf);
		exit(EXIT_FAILURE);
	}
	return (buf);
}
