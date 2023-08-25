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
		args[arg_count - 1][strlen(args[arg_count - 1]) - 1] = '\0'; /* Remove newline character */
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
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		/* Child process */
		execvp(command, args);

		/* If execvp returns, it means the command couldn't be executed */
		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		waitpid(pid, NULL, 0);
	}
}
