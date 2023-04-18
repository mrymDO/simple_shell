#include "simple_shell.h"

extern char **environ;

char *_getenv(const char *varname)
{
	char *add;
	int len = strlen(varname);
	int i = 0;

	while(environ[i])
	{
		if (strncmp(environ[i], varname, len) == 0)
		{
			add = strchr(environ[i], '=');
			if (add)
				return (add + 1);
		}
		i++;
	}
	return (NULL);
}
