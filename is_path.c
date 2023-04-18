#include "simple_shell.h"

int is_path(char *cmd)
{
	struct stat st;

	if (stat(cmd,&st) == 0)
		return (1);
	return (0);
}
