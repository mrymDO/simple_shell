#include "simple_shell.h"

/**
 * check_built_n - check for built n.
 * @args: arr of strings.
 * env: environment variables.
 *
 * Return: void.
 */

void check_built_n(char **args, char **env)
{
	if (_strcmp(args[0], "setenv") == 0)
		set_env(args, env);

	if (_strcmp(args[0], "unsetenv") == 0)
		unset_env(args, env);

	if (_strcmp(args[0], "cd") == 0)
		change_dir(args);

	if (_strcmp(args[0], "env") == 0)
		is_input_env(args);
}
/**
 * execute_cmd - execute a command with its arguments
 * @args: represents the command and its arguments
 * @argv: represents the arguments passed to the main function
 * @env: represents the environ,ent variable of current process
 * @atty: check if intractive or not
 * @buf: input line
 * Return: void. 
 */

void execute_cmd(char **args, char **argv, char **env, int atty, char *buf)
{
	char *path;

	check_built_n(args, env);
		return;

	if (is_path(args[0]))
	{
		forking(args, env);
		return;
	}
	else
	{
		path = get_path(args[0]);
		if (path != NULL)
		{
			args[0] = _realloc(args[0], _strlen(path) + 1);
			if (args[0])
			{
				_strcpy(args[0], path);
				forking(args, env);
			}
			if (path)
			{
				free(path);
				path = NULL;
			}
		}
		else
		{
			if (atty)
				fprintf(stderr, "%s : %d: %s: not found\n", argv[0], 1, buf);
			else
				perror(argv[0]);
		}
	}
}
