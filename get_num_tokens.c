#include "simple_shell.h"

unsigned int get_num_tokens(char *buf)
{
	unsigned int num_tokens = 0;
	char *piece = NULL;

	piece = strtok(buf, " \n");
	while(piece != NULL)
	{
		num_tokens++;
		piece = strtok(NULL, " \n");
	}
	return (num_tokens);
}
