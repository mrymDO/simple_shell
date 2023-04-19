#include "simple_shell.h"

/**
 * _getline - reads an entire line from stream
 * @n: the size of the buffer pointed to by *lineptr
 * ]stream: pointer to filee stream from which to read the input line
 * Return: number of char read including '\n' excluding '\0'
 * if error occurs or EOF, return -1
 */

#define SIZE 256

ssize_t _getline(char **lineptr, size_t *n, char *stream)
{
	static char buffer[SIZE];
	size_t size = *n;
	int fd;
	ssize_t n_read = 0;
	size_t total_read = 0;
	char *p;

	if (*lineptr == NULL)
	{
		*lineptr = malloc(size);
		if (*lineptr == NULL)
			return (-1);
	}

	fd = open(stream, O_RDONLY);
	if (fd == -1)
		return (-1);

	while ((n_read = read(fd, buffer, SIZE)) > 0)
	{
		total_read += n_read;
		p = buffer;
		while (n_read > 0)
		{
			if (*n <= total_read)
			{
				size *= 2;
				*lineptr = realloc(*lineptr, size);
				if (*lineptr == NULL)
				{
					close(fd);
					free(*lineptr);
					return (-1);
				}
				*n = size;
			}
			(*lineptr)[total_read++] = *p++;
			n_read--;
		}
		if (*(p - 1) == '\n')
			break;
	}
	close(fd);

	if (total_read == 0 && n_read <= 0)
		return (-1);

	(*lineptr)[total_read] = '\0';
	return (total_read);
}


