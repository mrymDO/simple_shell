#include "simple_shell.h"

void set_env(char **args, char **env)
{
        int i = 0, len = 0;
        char **en;

        while (args[i])
        {
                len++;
                i++;
        }
        if(args[1] && args[2])
        {
                en = malloc(sizeof(char *) * (len + 2));
                if (en == NULL)
			return;
		for (i = 0; env[i]; i++)
                	en[i] = env[i];

		en[i] = malloc(strlen(args[1]) + strlen(args[2]) + 2);
		if (en[i] == NULL)
			return;
		strcpy(en[i], args[1]);
		strcat(en[i], "=");
		strcat(en[i], args[2]);
                en[i + 1] = NULL;

                env = en;

                i = 0;
                while (en[i])
                {
                        printf("%s\n", en[i]);
                        i++;
		}
	}
	return;
}
