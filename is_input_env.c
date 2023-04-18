#include "simple_shell.h"

int is_input_env(char **args, char **env)
{
	int i = 0, len = 0;

	while (args[i])
	{
		len++;
		i++;
	}
	i = 0;
	if (_strcmp(args[0], "env") == 0 && len == 1)
	{
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	return (1);
	}
	return (0);
}
