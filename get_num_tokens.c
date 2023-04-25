#include "simple_shell.h"
/**
 * get_num_tokens - count number of words int the string
 * @buf: pointer to character buffer containing a string
 * Return: total number of tokens
 */

unsigned int get_num_tokens(char *buf)
{
	unsigned int num_tokens = 0;
	char *piece = NULL;

	piece = strtok(buf, " \t\n");
	while (piece != NULL)
	{
		if (piece[0] == '#')
			break;
		num_tokens++;
		piece = strtok(NULL, " \t\n");
	}
	return (num_tokens);
}
