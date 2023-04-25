#include "simple_shell.h"

/**
 * split_dirs - split PATH value into tokens and return them in arr.
 * @env_dirs: the environment variable PATH.
 *
 * Return: an array of paths.
 */

char **split_dirs(char *env_dirs)
{
<<<<<<< HEAD
	char **arr_dirs = NULL;
	int i = 0, num_dirs = 0;
	char *piece;
	char *env_dirs_copy;
=======
        char **arr_dirs = NULL;
        int i = 0, num_dirs = 0, j;
        char *piece;
        char *env_dirs_copy = NULL;
>>>>>>> a4e13f7ba565407c56907b28971766d4fafbce66

	if (env_dirs)
		env_dirs_copy = _strdup(env_dirs);

	piece = strtok(env_dirs_copy, ":");
	while (piece != NULL)
	{
		num_dirs++;
		piece = strtok(NULL, ":");
	}

	arr_dirs = malloc(sizeof(char *) * (num_dirs + 1));
	if (arr_dirs == NULL)
		return (NULL);

	piece = strtok(env_dirs, ":");
	i = 0;
	while (piece != NULL)
	{
		arr_dirs[i] = malloc(sizeof(char) * (_strlen(piece) + 1));
		if (arr_dirs[i] == NULL)
<<<<<<< HEAD
=======
		{
			for (j = 0; j < i; j++)
                		free(arr_dirs[j]);
			free(arr_dirs);
			free(env_dirs_copy);
>>>>>>> a4e13f7ba565407c56907b28971766d4fafbce66
			return (NULL);
		_strcpy(arr_dirs[i], piece);
		piece = strtok(NULL, ":");
		i++;
	}

	arr_dirs[i] = NULL;
	free(env_dirs_copy);
	return (arr_dirs);
}
