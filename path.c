#include "main.h"

/**
 * find_path - Looks for a command in the directories listed in PATH.
 * @command: The command name (e.g., "ls").
 *
 * Return: Full path if found, or NULL if not found or if it's already a path.
 */
char *find_path(char *command)
{
	char *path_env = NULL, *path_copy = NULL, *token = NULL;
	char *file_path = NULL;
	struct stat st;
	int i;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
	}
	if (!path_env || *path_env == '\0')
		return (NULL);

	path_copy = strdup(path_env);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		file_path = malloc(strlen(token) + strlen(command) + 2);
		if (!file_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(file_path, "%s/%s", token, command);
		if (stat(file_path, &st) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
