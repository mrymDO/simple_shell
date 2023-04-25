#include "simple_shell.h"

/**
 * get_path - get the full path for the command entred.
 * @cmd: the command entred.
 *
 * Return: the full path. NULL otherwise.
 */

char *get_path(char *cmd)
{
	char *path, *path1, *path2, **dirs;
	int i = 0;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	path1 = _strdup(path);
	if (path1 == NULL)
		return (NULL);

	dirs = split_dirs(path1);
	if (dirs == NULL)
		return (NULL);
	free(path1);

	while (dirs[i++])
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
	}
	free_arr_of_strs(dirs);
	return (NULL);
}
