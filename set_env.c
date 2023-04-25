#include "simple_shell.h"
/**
 * set_env - set an environment variable.
 * @args: array of strings.
 * @env: environment variables.
 *
 * Return: void.
 */

void set_env(char **args, char **env)
{
	int i = 0, len = 0;
	char **en;

	while (args[i])
	{
		len++;
		i++;
	}
	if (args[1] && args[2])
	{
		en = malloc(sizeof(char *) * (len + 2));
		if (en == NULL)
			return;
		for (i = 0; env[i]; i++)
			en[i] = env[i];

		en[i] = malloc(_strlen(args[1]) + _strlen(args[2]) + 2);
		if (en[i] == NULL)
			return;
		_strcpy(en[i], args[1]);
		_strcat(en[i], "=");
		_strcat(en[i], args[2]);
		en[i + 1] = NULL;
		env = en;
	}
}
