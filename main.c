#include "shell.h"

/**
 * main - Simple Shell main function
 * @ac: The counter of arguments
 * @argv: Arguments
 * Return: 0 Always (success).
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **COMMAND = NULL;
	int status = 0, IDX = 0;

	(void)ac;

	while (1)
	{
		line = READ_LINE();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		IDX++;
		COMMAND = TOKENIZER(line);
		if (!COMMAND)
			continue;

		if (my_builtin(COMMAND[0]))
			builtin_handler(COMMAND, argv, &status, IDX);
		else
		status = _EXECUTE(COMMAND, argv, IDX);
	}
}

