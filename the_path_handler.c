#include "shell.h"

/**
 * search_directories - Searches directories in PATH for the command.
 * @cmd: The command to locate.
 * @path_env: The PATH environment variable.
 * @my_st: The stat structure.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *search_directories(char *cmd, char *path_env, struct stat *my_st);

/**
 * build_full_command - Builds the full path of the command.
 * @cmd: The command to locate.
 * @directory: The directory to append.
 *
 * Return: The full path of the command.
 */
char *build_full_command(char *cmd, char *directory);

/**
 * _getpath - Finds the full path of a command.
 * @cmd: The command to locate.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *_getpath(char *cmd)
{
	char *path_env, *DIRECTORY;
	int i;
	struct stat my_st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &my_st) == 0)
				return (my_strdup(cmd));

			return (NULL);
		}
	}

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	DIRECTORY = search_directories(cmd, path_env, &my_st);
	free(path_env);
	return (DIRECTORY);
}

/**
 * search_directories - Searches directories in PATH for the command.
 * @cmd: The command to locate.
 * @path_env: The PATH environment variable.
 * @my_st: The stat structure.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *search_directories(char *cmd, char *path_env, struct stat *my_st)
{
	char *DIRECTORY = strtok(path_env, ":");
	char *FULL_COMMAND;

	while (DIRECTORY)
	{
		FULL_COMMAND = build_full_command(cmd, DIRECTORY);
		if (FULL_COMMAND)
		{
			if (stat(FULL_COMMAND, my_st) == 0)
				return (FULL_COMMAND);

			free(FULL_COMMAND);
		}

		DIRECTORY = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * build_full_command - Builds the full path of the command.
 * @cmd: The command to locate.
 * @directory: The directory to append.
 *
 * Return: The full path of the command.
 */
char *build_full_command(char *cmd, char *directory)
{
	char *FULL_COMMAND = malloc(my_strlen(directory) + my_strlen(cmd) + 2);

	if (FULL_COMMAND)
	{
		my_strcpy(FULL_COMMAND, directory);
		my_strcat(FULL_COMMAND, "/");
		my_strcat(FULL_COMMAND, cmd);
	}

	return (FULL_COMMAND);
}

