#include "simple_shell.h"
/**
 * get_path - get the full path for the command entred.
 * @cmd: the command entred.
 *
 * Return: the full path. NULL otherwise.
 */

char *get_path(char *cmd)
{
	char *pat = getenv("PATH");
	char *pat1 = strdup(pat);
	char **dirs = split_dirs(pat1);
	char *path;
	struct stat st;
	int i = 0;

	free(pat1);
	i = 0;
	while (dirs[i])
	{
		path = malloc(sizeof(char) * (strlen(dirs[i]) + strlen(cmd) + 2));
		strcat(path, dirs[i]);
		strcat(path, "/");
		strcat(path, cmd);
		if (stat(path, &st) == 0)
			return (path);
		i++;
	}
	return (NULL);
}
