#include "shell.h"

/**
 * count_tokens - Counts the number of tokens in a string.
 * @line: The string to count tokens in.
 *
 * Return: The number of tokens.
 */
static int count_tokens(char *line)
{
	char *TOKEN, DELIM[] = " \t\n";
	int count = 0;

	if (!line)
		return (0);

	TOKEN = strtok(line, DELIM);
	while (TOKEN)
	{
		count++;
		TOKEN = strtok(NULL, DELIM);
	}

	return (count);
}

/**
 * allocate_and_copy_tokens - Allocates memory for tokens and copies them.
 * @line: The original string.
 * @count: The number of tokens.
 *
 * Return: An array of tokens, or NULL on failure.
 */
static char **allocate_and_copy_tokens(char *line, int count)
{
	char *TOKEN, DELIM[] = " \t\n";
	char **COMMAND = NULL;
	int i = 0;


	COMMAND = malloc(sizeof(char *) * (count + 1));
	if (!COMMAND)
		return (NULL);

	TOKEN = strtok(line, DELIM);
	while (TOKEN)
	{
		COMMAND[i] = my_strdup(TOKEN);
		TOKEN = strtok(NULL, DELIM);
		i++;
	}
	COMMAND[i] = NULL;
	return (COMMAND);
}

/**
 * TOKENIZER - Tokenizes a string into an array of tokens.
 * @line: The string to tokenize.
 *
 * Return: An array of tokens, or NULL if memory allocation fails.
 */
char **TOKENIZER(char *line)
{
	char *TMP = NULL;
	char **COMMAND = NULL;
	int count = 0;

	if (!line)
		return (NULL);

	TMP = my_strdup(line);
	if (!TMP)
		return (NULL);

	count = count_tokens(TMP);
	free(TMP), TMP = NULL;

	if (count == 0)
		return (NULL);

	COMMAND = allocate_and_copy_tokens(line, count);
	free(line), line = NULL;

	return (COMMAND);
}

