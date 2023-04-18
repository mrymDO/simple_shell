#include "simple_shell.h"

char **fill_arr_by_tokens(char *buf_copy, char **args)
{
	char *piece = NULL;
	int i = 0;

	piece = strtok(buf_copy, " \"\n");
	while(piece != NULL)
	{
		args[i] = malloc(sizeof(char) * (strlen(piece) + 1));
		strcpy(args[i], piece);
		piece = strtok(NULL, " \"\n");
		i++;
	}
	args[i] = NULL;
	return (args);
}
