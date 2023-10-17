#include "shell.h"

/**
 * my_builtin - Check if a command is a built-in.
 * @COMMAND: The command to check.
 * Return: 1 if it's a built-in, 0 otherwise.
 */
int my_builtin(char *COMMAND)
{
	char *the_builtins[] = {
		"exit", "env", "setenv", "cd", NULL
	};

	int i;

	for (i = 0; the_builtins[i]; i++)
	{
		if (my_strcmp(COMMAND, the_builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * builtin_handler - Handle built-in commands.
 * @COMMAND: The command to handle.
 * @argv: Command-line arguments.
 * @status: The exit status.
 * @IDX: The index.
 */
void builtin_handler(char **COMMAND, char **argv, int *status, int IDX)
{
	if (my_strcmp(COMMAND[0], "exit") == 0)
		the_shell_exit(COMMAND, argv, status, IDX);
	else if (my_strcmp(COMMAND[0], "env") == 0)
		theprint_env(COMMAND, status);
}

/**
 * the_shell_exit - Handle the "exit" built-in command.
 * @COMMAND: The command.
 * @argv: Command-line arguments.
 * @status: The exit status.
 * @IDX: The index.
 */
void the_shell_exit(char **COMMAND, char **argv, int *status, int IDX)
{
	int exit_VALUE = (*status);
	char *INDEX, message[] = ": exit: Illegal number: ";

	if (COMMAND[1])
	{
		if (!_positive_num(COMMAND[1]))
		{
			INDEX = _itoa(IDX);
			write(STDERR_FILENO, argv[0], my_strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, INDEX, my_strlen(INDEX));
			write(STDERR_FILENO, message, my_strlen(message));
			write(STDERR_FILENO, COMMAND[1], my_strlen(COMMAND[1]));
			write(STDERR_FILENO, "\n", 1);
			free(INDEX);
			FREE2Darr(COMMAND);
			(*status) = 2;
			return;
		}
		exit_VALUE = _atoi(COMMAND[1]);
	}
	FREE2Darr(COMMAND);
	exit(exit_VALUE);
}

/**
 * theprint_env - Handle the "env" built-in command.
 * @COMMAND: The command.
 * @status: The exit status.
 */
void theprint_env(char **COMMAND, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], my_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	FREE2Darr(COMMAND);
	(*status) = 0;
}

