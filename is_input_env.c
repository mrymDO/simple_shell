#include "simple_shell.h"

/**
 * is_input_env - check if the input equal env command.
 * @args: user's input.
 * @env: command entred.
 *
 * Return: void.
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
	if (len == 1)
	{
		while (env[i])
		{
			write(1, env[i], _strlen(env[i]));
			i++;
		}
	}
}
