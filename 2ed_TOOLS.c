#include "shell.h"

/**
 * _positive_num - Check if a string contains only positive digits.
 * @str: The string to check.
 * Return: 1 if all characters are digits, 0 otherwise.
 */
int _positive_num(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - Convert a string to an integer.
 * @str: The string to convert.
 * Return: The integer value of the string.
 */
int _atoi(char *str)
{
	int i, number = 0;

	for (i = 0; str[i]; i++)
	{
		number *= 10;
		number += (str[i] - '0');
	}
	return (number);
}

