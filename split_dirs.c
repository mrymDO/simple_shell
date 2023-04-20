#include "simple_shell.h"

/**
<<<<<<< HEAD
 * split_dirs - split PATH value into tokens and return them in arr.
 * @env_dirs: the environment variable PATH.
 *
 * Return: an array of paths.
=======
 * split_dirs - split strings into tokens
 * @env_dirs: the string to tokenized
 * Return: pointer to an array of strings (tokens)
>>>>>>> 7748e8a92af72fdbe1b11d58fa25ca5773a4aaa0
 */

char **split_dirs(char *env_dirs)
{
	char **arr_dirs = NULL;
	int i = 0, num_dirs = 0;
	char *piece;
<<<<<<< HEAD
	char *env_dirs_copy = strdup(env_dirs);
=======
	char *env_dirs_copy = _strdup(env_dirs);
>>>>>>> 7748e8a92af72fdbe1b11d58fa25ca5773a4aaa0

	piece = strtok(env_dirs_copy, ":");
	while (piece != NULL)
	{
		piece = strtok(NULL, ":");
		num_dirs++;
	}

	arr_dirs = malloc(sizeof(char *) * (num_dirs + 1));

	piece = strtok(env_dirs, ":");
	i = 0;
	while (piece != NULL)
	{
<<<<<<< HEAD
		arr_dirs[i] = malloc(sizeof(char) * (strlen(piece) + 1));
		strcpy(arr_dirs[i], piece);
=======
		arr_dirs[i] = malloc(sizeof(char) * (_strlen(piece) + 1));
		_strcpy(arr_dirs[i], piece);
>>>>>>> 7748e8a92af72fdbe1b11d58fa25ca5773a4aaa0
		piece = strtok(NULL, ":");
		i++;
	}

	arr_dirs[i] = NULL;
	free(env_dirs_copy);
	return (arr_dirs);
}
