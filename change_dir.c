#include "simple_shell.h"

int change_dir(char **args)
{
	struct stat st;
	int i = 0, len = 0;
	char *buf = NULL;
	size_t size = 0;

	while(args[i])
	{
		len++;
		i++;
	}

	if (len == 1 )
	{
		if (chdir(_getenv("HOME")) == -1)
		{
			perror("chdir error");
			exit(1);
		}
		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", _getenv("HOME"), 1);
		return (1);
	}
	if (args[1] && stat(args[1], &st) == 0 && len == 2)
	{
			if (chdir(args[1]) == -1)
			{
				perror("chdir error");
				exit(1);
			}
			setenv("OLDPWD", _getenv("PWD"), 1);
			setenv("PWD", getcwd(buf, size), 1);
			return (1);
	}
	if (args[1][0] == '-')
                {
                        if (chdir(_getenv("OLDPWD")) == -1)
                        {
                                perror("chdir error");
                                exit(1);
                        }
                        setenv("OLDPWD", _getenv("PWD"), 1);
                        setenv("PWD", getcwd(buf, size), 1);
                        return (1);
                }
	perror("cd ");
	return (0);
}
