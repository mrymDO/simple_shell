#include "simple_shell.h"

void forking(char *args[])
{
		pid_t pid;
		int status;
		pid = fork();

                if (pid == -1)
                {
                        perror("fork error");
                        return;
                }
                if (pid == 0)
                {
                        if (execve(args[0], args, NULL) == -1)
                        {
                                        perror("execve error");
                			return;
                	}
                }
                else
                {
                        if (wait(&status) == -1)
                        {
                                perror("wait error");
                                return;
                        }
                }
}
