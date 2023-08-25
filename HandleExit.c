#include "main.h"

/**
 * HandleExit - Handle the exit command.
 *
 * This function handles the "exit"
 * ... command by freeing allocated memory and
 * terminating the program with a status
 * ... of 0. It takes as input the TokenizeInputized
 * command and the input line read
 * ... from `stdin`. The allocated memory for the
 * command array and the input line
 * ... are both freed before the program exits.
 *
 * @command: Tokenized command array.
 * @line: Input line read from `stdin`.
 */
void HandleExit(char **command, char *line)
{
    free(line);
    FreeBuffers(command); /* Assuming this is your own function to free memory */
    exit(0);
}
