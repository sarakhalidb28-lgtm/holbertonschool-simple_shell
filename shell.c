#include "main.h"

/**
 * execute_command - execute user command
 * @args: command arguments
 *
 * Return: nothing
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}

/**
 * main - simple shell
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL, *args[100], *token;
	size_t len = 0;
	int i;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (getline(&line, &len, stdin) == -1)
		{
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

		if (args[0] != NULL)
			execute_command(args);
	}

	free(line);
	return (0);
}
