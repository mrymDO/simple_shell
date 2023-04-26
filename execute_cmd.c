#include "simple_shell.h"

/**
 * check_built_n - check for built n.
 * @args: arr of strings.
 * env: environment variables.
 *
 * Return: 1 on success. 0 otherwise.
 */

void check_built_n(char **args, char **env)
{
	is_input_exit(args);

	if (_strcmp(args[0], "setenv") == 0)
		set_env(args, env);

	if (_strcmp(args[0], "unsetenv") == 0)
		unset_env(args, env);

	if (_strcmp(args[0], "cd") == 0)
		change_dir(args);

	is_input_env(args, env);
}
/**
 * execute_cmd - execute a command with its arguments
 * @args: represents the command and its arguments
 * @argv: represents the arguments passed to the main function
 * @env: represents the environ,ent variable of current process
 * @atty: check if intractive or not
 * @buf: input line
 * Return: 0 if command is executed and 1 if there is an error
 */

void execute_cmd(char **args, char **argv, char **env, int atty, char *buf)
{
	char *path;

	check_built_n(args, env);

	if (is_path(args[0]))
	{
		forking(args, env);
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
