#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_chars;

	while (1)
	{
		printf("#cisfun$ ");
		read_chars = getline(&input, &input_size, stdin);

		if (read_chars == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break; /* End of file (Ctrl+D) */
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}

		/* Remove newline character from input */
		input[strcspn(input, "\n")] = '\0';

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0) /* Child process */
		{
			char *args[] = {input, NULL};
			if (execve(input, args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else /* Parent process */
		{
			int status;
			waitpid(pid, &status, 0);
		}
	}

	free(input);
	return (EXIT_SUCCESS);
}
