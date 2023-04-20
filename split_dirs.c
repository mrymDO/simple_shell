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
	char *env_dirs_copy = strdup(env_dirs);

	piece = strtok(env_dirs_copy, ":");
	while (piece != NULL)
	{
		piece = strtok(NULL, ":");
		num_dirs++;
	}
=======
        char **arr_dirs = NULL;
        int i = 0, num_dirs = 0;
        char *piece;
        char *env_dirs_copy = _strdup(env_dirs);

        piece = strtok(env_dirs_copy, ":");
        while (piece != NULL)
        {
                piece = strtok(NULL, ":");
                num_dirs++;
        }
>>>>>>> bc16b26... add implemented functions

	arr_dirs = malloc(sizeof(char *) * (num_dirs + 1));

<<<<<<< HEAD
	piece = strtok(env_dirs, ":");
	i = 0;
	while (piece != NULL)
	{
		arr_dirs[i] = malloc(sizeof(char) * (strlen(piece) + 1));
		strcpy(arr_dirs[i], piece);
		piece = strtok(NULL, ":");
		i++;
	}
=======
        piece = strtok(env_dirs, ":");
        i = 0;
        while (piece != NULL)
        {
                arr_dirs[i] = malloc(sizeof(char) * (_strlen(piece) + 1));
                _strcpy(arr_dirs[i], piece);
                piece = strtok(NULL, ":");
                i++;
        }
>>>>>>> bc16b26... add implemented functions

	arr_dirs[i] = NULL;
	free(env_dirs_copy);
	return (arr_dirs);
}
