#include "simple_shell.h"

char **check_for_comts(char **args)
{
	int i = 0, len = 0;
	char **tmp;

	while(args[i])
	{
		if (_strcmp(args[i], "#") == 0)
		break;
		len++;
		i++;
	}
	tmp = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while(args[i] && i < len)
	{
		tmp[i] = args[i];
		i++;
	}
	tmp[i] = NULL;
	if (len)
	{
		return (tmp);
	}
	else
		return (NULL);
}
