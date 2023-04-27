#include "simple_shell.h"

/**
 * check_built_n - check for built n.
 * @args: arr of strings.
 * @argv: command's arguments
 * @env: environment variables.
 * @buf1: buffer1
 * @buf2: buffer2
 * @buf3: buffer3
 *
 * Return: 1 on success. 0 otherwise.
 */

int check_built_n(char **args, char **argv, char **env, char *buf1, char *buf2, char *buf3)
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

	if (_strcmp(args[0], "env") == 0)
	{
		is_input_env(args);
		return (1);
	}
	if (_strcmp(args[0], "exit") == 0)
	{
		is_input_exit(args, argv, buf1, buf2, buf3);
		return (1);
	}
	return (0);

}
/**
 * execute_cmd - execute a command with its arguments
 * @args: represents the command and its arguments
 * @argv: represents the arguments passed to the main function
 * @env: represents the environ,ent variable of current process
 * @atty: check if intractive or not
 * @buf1: buffer1
 * @buf2: buffer2
 * @buf3: buffer3
 * Return: void.
 */

void execute_cmd(char **args, char **argv, char **env,
		int atty, char *buf1, char *buf2, char *buf3)
{
	char *path;

	if (check_built_n(args, argv, env, buf1, buf2, buf3))
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
				fprintf(stderr, "%s : %d: %s: not found\n", argv[0], 1, buf1);
			else
				perror(argv[0]);
		}
	}
}
