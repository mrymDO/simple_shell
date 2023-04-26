#include "simple_shell.h"

/**
 * is_input_env - check if the input equal env command.
 * @args: user's input.
 * @env: command entred.
 *
 * Return: 1 on success. 0 otherwise.
 */

void is_input_env(char **args, char **env)
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
	}
}
