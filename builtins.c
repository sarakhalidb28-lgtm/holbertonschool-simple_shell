#include "main.h"

/**
 * handle_builtins - Checks and executes built-in shell commands.
 * @args: Array of tokenized arguments.
 *
 * Return: 1 if a built-in was executed, 0 otherwise.
 */
int handle_builtins(char **args)
{
	int i;

	if (!args || !args[0])
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}

	return (0);
}
