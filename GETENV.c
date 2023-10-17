#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @var: The name of the environment variable
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(char *var)
{
	char *TMP;
	char *KEY;
	char *VALUE, *ENV;
	int i;

	for (i = 0; environ[i]; i++)
	{
		TMP = my_strdup(environ[i]);
		KEY = strtok(TMP, "=");
		if (my_strcmp(KEY, var) == 0)
		{
			VALUE = strtok(NULL, "\n");
			ENV = my_strdup(VALUE);
			free(TMP);
			return (ENV);
		}
		free(TMP);
		TMP = NULL;
	}
	return (NULL);
}

