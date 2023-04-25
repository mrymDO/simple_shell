#include "simple_shell.h"

/**
 * unset_env - remove an environment variable.
 * @args: array of strings.
 * @env: environment variables.
 *
 * Return: void
 */

void unset_env(char **args, char **env)
{
	char **en;
	int i = 0, len = 0;

	while (args[i++])
		len++;
	if (len == 2)
	{
		en = malloc(sizeof(char *) * len);
		for (i = 0; env[i]; i++)
		{
			if (_strncmp(env[i], args[1], _strlen(args[1])) == 0)
				continue;
			en[i] = env[i];
		}
		en[i] = NULL;
		env = en;
		i = 0;
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
}
