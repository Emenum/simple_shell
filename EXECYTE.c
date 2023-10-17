#include "shell.h"

/**
 * _EXECUTE - Executes a command in a child process.
 * @COMMAND: An array of strings representing the command and its arguments.
 * @argv: Arguments.
 * @IDX: The index indicating the position of the command
 * within the COMMAND array.
 * Return: The exit status of the child process.
 */
int _EXECUTE(char **COMMAND, char **argv, int IDX)
{
	char *FULL_CMD;
	pid_t child_pid;
	int status;

	FULL_CMD = _getpath(COMMAND[0]);
	if (!FULL_CMD)
	{
		printerror(argv[0], COMMAND[0], IDX);
		FREE2Darr(COMMAND);
		return (127);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(FULL_CMD, COMMAND, environ) == -1)
		{
			free(FULL_CMD), FULL_CMD = NULL;
			FREE2Darr(COMMAND);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		FREE2Darr(COMMAND);
		free(FULL_CMD), FULL_CMD = NULL;
	}
	return (WEXITSTATUS(status));
}

