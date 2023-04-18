#include "simple_shell.h"

void free_arr_of_strs(char **arr)
{
	int i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
