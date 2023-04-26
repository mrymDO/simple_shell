#include "simple_shell.h"

/**
 * _getenv - searches environment list to find the environement variable name
 * @varname: string containing the requested variable
 * Return: a pinter to the corresponding value of the requested env variable
 * NULL if there is no much
 */

char *_getenv(const char *varname)
{
	char *add;
	int len = _strlen(varname);
	int i = 0;

	while (environ[i])
	{
		if (_strncmp(environ[i], varname, len) == 0)
		{
			add = _strchr(environ[i], '=');
			if (add)
				return (add + 1);
		}
		i++;
	}
	return (NULL);
}
