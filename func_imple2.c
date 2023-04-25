#include "simple_shell.h"

/**
 * _strdup - duplicates a string
 * @s: string to be duplicated
 * Return: a pointer to the duplicated string
 */

char *_strdup(const char *s)
{
	char *ptr, *dup;
	int length = 0;

	while (s[length] != '\0')
		length++;

	length++;

	dup = malloc(length);
	if (dup == NULL)
		return (NULL);


	ptr = dup;
	while (*s)
	{
		*ptr++ = *s++;
	}

	*ptr = '\0';

	return (dup);
}

/**
 * _strncmp - A function that compares two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to be compared
 * Return: 0 (success)
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] == '\0' || s2[i] == '\0')
			break;
	}
	return (0);
}

/**
 * _realloc - function that reallocates a memory block
 * @ptr: pointer to the start of a peice of memory space previously allocated
 * @size: new total byte number to the new memory block
 * Return: a pointer to the new memory block. else return NULL if it failled
 */

void *_realloc(void *ptr, unsigned int size)
{
	void *p;

	if (ptr != NULL && size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		p = malloc(size);
		if (p == NULL)
		{
			return (NULL);
		}
		return (p);
	}


	p = malloc(size);
	if (p == NULL)
		return (NULL);

	_memcpy(p, ptr, size); /* the size of the old memory block is at least size */

	free(ptr);

	return (p);
}

/**
 * _memcpy - copies memory area
 * @dest: destination array where the content to be copied
 * @src: source of data to be copied
 * @n: number of bytes to be copied
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _atoi - function that converts a string  to an integer
 * @s : the string that we need to convert
 * Return: integer (represents the conversion of the string)
 */

int _atoi(char *s)
{
	int i, j = 0, k = -1;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-')
			k *= -1;
		if (s[i] > 47 && s[i] < 58)
		{
			if (j < 0)
				j = (j * 10) - (s[i] - '0');
			j = (s[i] - '0') * -1;

			if (s[i + 1] <= 47 || s[i + 1] >= 58)
				break;
		}
	}
	if (k < 0)
		j *= -1;
	return (j);
}

