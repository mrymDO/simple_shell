#include "simple_shell.h"

/**
 *  _strlen - A function that returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcpy - a function that copies a string
 * @dest:  buffer pointed to by dest
 * @src: string pointed to by src
 * Return: the pointer to dest
 */

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

/**
 * _strcat - A function that concatenates two strings
 * @dest: destination of the string
 * @src: source of the string
 * Return: two concat strings
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i])
	{
		i++;
	}

	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - A function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 (success)
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}


/**
 * _strchr - locates a character in a string
 * @s: string to be scanned
 * @c: the character to be searched in str
 * Return: the first occurence of chracter c or NULL if character not found
 */

char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		return ((char *)s);
		s++;
	}
	return (NULL);
}


