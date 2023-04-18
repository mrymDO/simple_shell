#include "simple_shell.h"
/**
 * is_path - check if the path exist or not.
 * @cmd: user's entered command.
 *
 * Return: 1 on success. 0 otherwise.
 */

int is_path(char *cmd)
{
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (1);
	return (0);
}
