#include "simple_shell.h"

int execute_cmd(char **args, char **argv, char **env)
{
	char *path;
	
	if (is_input_exit(args))
		exit(0);
	if (is_input_env(args, env))
		return (1);
	if (is_path(args[0]))
		forking(args);
	else
	{
		path = get_path(args[0]);
		if (path != NULL)
		{
				args[0] = realloc(args[0], strlen(path) + 1);
				strcpy(args[0], path);
				forking(args);
		}
		else
			perror(argv[0]);
	}
	return (0);
}
