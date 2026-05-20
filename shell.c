#include "main.h"

int main(void)
{
	char *line = NULL;
	char *args[100];
	char *token;
	size_t len = 0;
	pid_t pid;
	int status;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		if (getline(&line, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(0);
		}

		line[strcspn(line, "\n")] = '\0';

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

		pid = fork();

		if (pid == 0)
		{
			execve(args[0], args, environ);
			exit(1);
		}
		else
			wait(&status);
	}

	free(line);
	return (0);
}
