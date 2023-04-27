#include "simple_shell.h"

/**
 * free_arr_of_strs - free the memory allocated for the array of strings
 * @arr: a pointer to an array of strings
 * Return: void
 */

void free_arr_of_strs(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
