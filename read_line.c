#include "simple_shell.h"

char *read_line()
{
	ssize_t chars_read = 0;
	size_t len = 0;
	char *buf = NULL;

	chars_read = getline(&buf, &len, stdin);
	if (chars_read == -1)
	{
		free(buf);
		perror("getline error");
		exit(1);
	}
	return (buf);
}
