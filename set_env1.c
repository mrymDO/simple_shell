#include "simple_shell.h"

extern char **environ;

void set_env1(char **args)
{
	int i = 0, len = 0;
	char **env;
	char *new_var;

	while (args[i])
	{
		len++;
		i++;
	}
	if(args[1] && args[2])
	{
		new_var = malloc(strlen(args[1]) + strlen(args[2]) + 2);
        	strcpy(new_var, args[1]);
        	strcat(new_var, "=");
        	strcat(new_var, args[2]);		

		env = malloc(sizeof(char *) * (len + 1));
		for (i = 0; environ[i]; i++)
		{
			env[i] = malloc(strlen(environ[i]) + 1);
                	strcpy(env[i], environ[i]);
		}
		env[i] = malloc(strlen(args[1]) + strlen(args[2]) + 2);
		strcpy(env[i], new_var);
		env[i + 1] = NULL;

		environ = env;

		i = 0;
		while (env[i])
                {
                        printf("%s\n", env[i]);
                        i++;
                }
		free_arr_of_strs(env);
		free(new_var);
	}
	return;
}
