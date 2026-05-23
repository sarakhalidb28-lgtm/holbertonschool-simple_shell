#include "main.h"

/**
 * main - Core execution loop for simple shell interpreter
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	char *args[100];
	char *token;
	char *full_path = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(0);
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		token = strtok(line, " ");
		i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (args[0] == NULL)
			continue;

		/* Pass line down here so it can clear memory leaks */
		if (handle_builtins(args, line))
			continue;

		full_path = find_path(args[0]);
		if (full_path == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(full_path, args, environ) == -1)
			{
				perror("Error");
				free(full_path);
				free(line);
				_exit(1);
			}
		}
		else
		{
			wait(&status);
		}
		free(full_path);
	}

	free(line);
	return (0);
}
