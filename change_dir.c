#include "simple_shell.h"

#define SIZE 1024
/**
 * change - execute chdir function.
 * @path: path to be executed.
 *
 * Return: 1 on success. -1 on failure.
 */

int change(char *path)
{
	char buf[SIZE];

	if (path != NULL)
	{
		if (chdir(path) == -1)
		{
			perror("chdir error");
			exit(EXIT_FAILURE);
		}
		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", getcwd(buf, SIZE), 1);
		return (1);
	}
	return (-1);
}

/**
 * change_dir - change current working directory.
 * @args: array of string entered.
 *
 * Return: 1 on success. 0 otherwise.
 */

int change_dir(char **args)
{
	int i = 0, len = 0;

	while (args[i])
	{
		len++;
		i++;
	}

	if (len == 1)
	{
		if (change(_getenv("HOME")))
			return (1);
	}
	if (args[1] && is_path(args[1]) && len == 2)
	{
		if (change(args[1]))
			return (1);
	}
	if (args[1][0] == '-')
	{
		if (change(_getenv("OLDPWD")))
			return (1);
	}
	perror("cd ");
	return (0);
}
