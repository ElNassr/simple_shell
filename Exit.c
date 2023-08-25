#include "main.h"

/**
* EXIT - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
*/
void EXIT(char **command, char *line)
{
	free(line);
	Free(command);
	exit(0);
}
