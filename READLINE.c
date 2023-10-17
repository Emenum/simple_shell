#include "shell.h"

/**
 * READ_LINE - Reads a line from standard input.
 *
 * Return: A pointer to the read line, or NULL on failure.
 */
char *READ_LINE(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nline;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "(sell)$ ", 8);
	}
	nline = getline(&line, &len, stdin);
	if (nline == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

