#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/* Function prototypes */
void execute_command(char *command, char **args);

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_length;
	char *args[64];
	int arg_count;

	while (1)
	{
		printf("#cisfun$ ");

		input_length = getline(&input, &input_size, stdin);

		if (input_length == -1)
		{
			printf("\n");
			break; /* Exit loop on EOF (Ctrl+D) */
		}

		input[input_length - 1] = '\0'; /* Remove newline character */

		arg_count = 0;
		args[arg_count] = strtok(input, " ");
		while (args[arg_count] != NULL)
		{
			arg_count++;
			args[arg_count] = strtok(NULL, " ");
		}
		args[arg_count] = NULL; /* Set the last argument to NULL */

		if (strcmp(args[0], "exit") == 0)
		{
			/* Built-in exit command */
			break;
		}

		execute_command(args[0], args);
	}

	/* Cleanup: free dynamically allocated memory */
	free(input);

	return 0;
}

/* Execute the given command with arguments */
void execute_command(char *command, char **args)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");
	int command_exists = 0;
	char command_path[MAX_INPUT_LENGTH];
	pid_t pid;

	while (path_token != NULL)
	{
		snprintf(command_path, sizeof(command_path), "%s/%s", path_token, command);

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
		pid = fork();

		if (pid < 0)
		{
			perror("fork");
		}
		else if (pid == 0)
		{
			/* Child process */
			execv(command_path, args);

			/* If execv returns, it means the command couldn't be executed */
			perror(command);
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
		printf("Command not found: %s\n", command);
	}
}
