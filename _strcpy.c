#include "sh.h"

char *_strcpy(char *dest, const char *src)
{
        int i = 0;
        int j = 0;

        while (src[i] != '\0')
        {
                i++;
        }
        for (; j < i; j++)
        {
                dest[j] = src[j];
        }

        dest[i] = '\0';
        return (dest);
}
