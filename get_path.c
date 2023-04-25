#include "simple_shell.h"

/**
 * get_path - get the full path for the command entred.
 * @cmd: the command entred.
 *
 * Return: the full path. NULL otherwise.
 */

char *get_path(char *cmd)
{
	char *path = _getenv("PATH");
	char *path1 = _strdup(path);
	char **dirs = split_dirs(path1);
	char *path2;
	int i = 0;

	free(path1);
	while (dirs[i])
	{
		path2 = malloc(sizeof(char) * (_strlen(dirs[i]) + _strlen(cmd) + 2));
		if (path2 == NULL)
		{
			free_arr_of_strs(dirs);
			return (NULL);
		}
		_strcat(path2, dirs[i]);
		_strcat(path2, "/");
		_strcat(path2, cmd);
		if (is_path(path2))
		{
			free_arr_of_strs(dirs);
			return (path2);
		}
		free(path2);
		i++;
	}
	free_arr_of_strs(dirs);
	return (NULL);
}
