#include "simple_shell.h"

/**
 * execute_cmd - execute a command with its arguments
 * @args: represents the command and its arguments
 * @argv: represents the arguments passed to the main function
 * @env: represents the environ,ent variable of current process
 * Return: 0 if command is executed and 1 if there is an error
 */

int execute_cmd(char **args, char **argv, char **env)
{
	char *path;

	if (_strcmp(args[0], "setenv") == 0)
        {
                set_env(args, env);
                return(1);
        }
	if (_strcmp(args[0], "unsetenv") == 0)
        {
                unset_env(args, env);
                return(1);
        }	
	if (_strcmp(args[0], "cd") == 0)
	{
		change_dir(args);
		return(1);
	}

	is_input_exit(args);
	
	if (is_input_env(args, env))
		return (1);
	if (is_path(args[0]))
		forking(args);
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
		}
		else
			perror(argv[0]);
		free(path);
	}
	return (0);
}
