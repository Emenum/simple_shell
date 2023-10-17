#include "shell.h"

/**
 * FREE2Darr - Frees a two-dimensional array of strings.
 * @arr: The array to free.
 *
 * This function takes a two-dimensional array of strings and frees the memory
 * associated with it. It also sets all pointers to NULL for safety.
 */

void FREE2Darr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
	arr = NULL;
}

/**
 * printerror - Print an error message to STDERR.
 * @name: The program name.
 * @CMD: The command causing the error.
 * @IDX: The index indicating the position of the command within the array.
 *
 * This function prints an error message to STDERR in the format:
 * "<name>: <IDX>: <CMD>: not found\n"
 * _itoa: Convert an integer to a string.
 */

void printerror(char *name, char *CMD, int IDX)
{
	char *INDEX, message[] = ": not found\n";

	INDEX = _itoa(IDX);
	write(STDERR_FILENO, name, my_strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, INDEX, my_strlen(INDEX));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, CMD, my_strlen(CMD));
	write(STDERR_FILENO, message, my_strlen(message));

	free(INDEX);
}

/**
 * _itoa - Convert an integer to a string.
 * @n: The integer to convert.
 *
 * This function converts an integer to a string representation and returns it.
 * The result is dynamically allocated and should be freed
 * when no longer needed.
 * Return: A pointer to the dynamically allocated string
 * representing the integer.
 */

char *_itoa(int n)
{
	char buff[20];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	reverse_string(buff, i);

	return (my_strdup(buff));

}

/**
 * reverse_string - Reverse a null-terminated string in place.
 * @str: The string to reverse.
 * @len: The length of the string.
 *
 * This function reverses a null-terminated string in place.
 */

void reverse_string(char *str, int len)
{
	char TMP;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		TMP = str[start];
		str[start] = str[end];
		str[end] = TMP;
		start++;
		end--;
	}
}

