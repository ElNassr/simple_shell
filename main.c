#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PATH_LENGTH 1024

/**
 * main - Entry point to the program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;

	while (1)
	{
		printf("#cisfun$ ");

		ssize_t input_length = getline(&input, &input_size, stdin);

		if (input_length == -1)
		{
			printf("\n");
			break; /* Exit loop on EOF (Ctrl+D) */
		}

		input[input_length - 1] = '\0'; /* Remove newline character */

		/* Tokenize input into command and arguments */
		char *args[64]; /* Maximum 64 arguments */
		int arg_count = 0;

		char *token = strtok(input, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL; /* Set the last argument to NULL */

		if (strcmp(args[0], "exit") == 0)
		{
			/* Built-in exit command */
			break;
		}

		/* Check if the command exists using the PATH */
		char *path = getenv("PATH");
		char *path_copy = strdup(path);
		char *path_token = strtok(path_copy, ":");
		int command_exists = 0;

		while (path_token != NULL)
		{
			char command_path[MAX_PATH_LENGTH];
			snprintf(command_path, sizeof(command_path), "%s/%s", path_token, args[0]);

			if (access(command_path, X_OK) == 0)
			{
				command_exists = 1;
				break;
			}

			path_token = strtok(NULL, ":");
		}

		free(path_copy);

		if (command_exists)
		{
			pid_t pid = fork();

			if (pid < 0)
			{
				perror("fork");
			}
			else if (pid == 0)
			{
				/* Child process */
				execv(args[0], args);

				/* If execv returns, it means the command couldn't be executed */
				perror(args[0]);
				exit(EXIT_FAILURE);
			}
			else
			{
				/* Parent process */
				waitpid(pid, NULL, 0);
			}
		}
		else
		{
			printf("Command not found: %s\n", args[0]);
		}
	}

	/* Cleanup: free dynamically allocated memory */
	free(input);

	return 0;
}
