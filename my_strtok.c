#include "simple_shell.h"

/**
 * my_strtok - parse a string
 * @str : string to be tokenized
 * @delim: delimiter
 * Return: pointer to the token
 */

char *my_strtok(char *str, char *delim)
{
	static char *ptr;
	char *piece;

	if (str != NULL)
		ptr = str;
	if (ptr == NULL || *ptr == '\0')
		return (NULL);

	piece = ptr;

	while (*ptr != '\0')
	{
		if (strchr(delim, *ptr) != NULL)
		{
			*ptr++ = '\0';
			break;
		}
		ptr++;
	}
	if (ptr == piece)
		return (my_strtok(NULL, delim));

	return (piece);
}
