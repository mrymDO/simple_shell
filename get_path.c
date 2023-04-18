#include "simple_shell.h"

char *get_path(char *cmd)
{
	char *pat = getenv("PATH");
	char *pat1 = _strdup(pat);
	char **dirs = split_dirs(pat1);
	char *path;
	struct stat st;
	int i = 0;

	free(pat1);

	i = 0;

	while (dirs[i])
	{
		path = malloc(sizeof(char) * (_strlen(dirs[i]) + _strlen(cmd) + 2));
		_strcat(path, dirs[i]);
		_strcat(path, "/");
		_strcat(path, cmd);
		if (stat(path, &st) == 0)
			return (path);
		i++;
	}
	return (NULL);
}
