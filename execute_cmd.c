#include "simple_shell.h"

/**
 * check_built_n - check if the command is built_in.
 * @args: array of strings.
 *
 * Return: 1 on success. 0 otherwise.
 */

int check_built_n(char **args, char **env)
{
	if (_strcmp(args[0], "setenv") == 0)
	{
		set_env(args, env);
		return (1);
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		unset_env(args, env);
		return (1);
	}
	if (_strcmp(args[0], "cd") == 0)
	{
		change_dir(args);
		return (1);
	}
	if (is_input_env(args, env))
		return (1);
	return (0);
}
/**
 * execute_cmd - execute a command with its arguments
 * @args: represents the command and its arguments
 * @argv: represents the arguments passed to the main function
 * @env: represents the environment variable of current process
 * Return: 1 on success. 0 otherwise.
 */

int execute_cmd(char **args, char **argv, char **env)
{
	char *path;

	if (check_built_n(args, env))
		return (1);

	if (is_path(args[0]))
	{
		forking(args);
		return (1);
	}
	else
	{
		path = get_path(args[0]);
		if (path != NULL)
		{
			args[0] = realloc(args[0], _strlen(path) + 1);
			if (args[0])
			{
				_strcpy(args[0], path);
				forking(args);
			}
			free(path);
		} else
			perror(argv[0]);
		return (1);
	}
	return (0);
}
