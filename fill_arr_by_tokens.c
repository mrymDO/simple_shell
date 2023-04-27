#include "simple_shell.h"

/**
 * fill_arr_by_tokens - split string into tokens,store them in array of strings
 * @buf_copy: the input srtring to be tokenized
 * @args: pointer to array of strings which will hold the resulting tokens
 * Return: array of strings which contains all tokens from input string
 */

char **fill_arr_by_tokens(char *buf_copy, char **args)
{
	char *piece = NULL;
	int i = 0;

	piece = strtok(buf_copy, " \t");
	while (piece != NULL)
	{
		if (piece[0] == '#')
			break;
		args[i] = malloc(sizeof(char) * (_strlen(piece) + 1));
		if (args[i] == NULL)
			return (NULL);
		_strcpy(args[i], piece);
		piece = strtok(NULL, " \t");
		i++;
	}
	args[i] = NULL;
	return (args);
}
