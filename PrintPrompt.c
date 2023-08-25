#include "main.h"

/**
 * PrintPrompt - Print the shell prompt.
 *
 * This function prints the shell prompt,
 * ... which is typically "$ ", to the standard
 * output. The prompt is only printed if
 * ... the shell is in interactive mode, which
 * is determined by checking if both
 * ... `STDIN_FILENO` and `STDOUT_FILENO` are attached
 * to a terminal.
 */
void PrintPrompt(void)
{
    if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
        _printchar("$ ", 2);
}
