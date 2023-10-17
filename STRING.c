#include "shell.h"

/**
 * my_strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string,
 * or NULL if memory allocation fails.
 */
char *my_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * my_strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int my_strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}

/**
 * my_strlen - Computes the length of a string.
 * @s: The string to measure.
 *
 * Return: The length of the string.
 */
int my_strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * my_strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to append.
 *
 * Return: A pointer to the destination string.
 */
char *my_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}

/**
 * my_strcpy - Copies a string.
 * @dest: The destination string.
 * @src: The source string to copy.
 *
 * Return: A pointer to the destination string.
 */
char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

