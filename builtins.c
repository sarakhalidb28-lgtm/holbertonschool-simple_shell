#include "main.h"

/**
 * handle_builtins - Checks and executes built-in shell commands.
 * @args: Array of tokenized arguments.
 * @line: The raw buffer allocated by getline to free on exit.
 * @status: Pointer to the tracking status integer of the last run command.
 *
 * Return: 1 if a built-in was executed, 0 otherwise.
 */
int handle_builtins(char **args, char *line, int *status)
{
	int i;
	int exit_code = 0;

	if (!args || !args[0])
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		/* If a child process ran before, evaluate its exact exit macro status */
		if (status && *status != 0)
			exit_code = WEXITSTATUS(*status);
		
		exit(exit_code);
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
