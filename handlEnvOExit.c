#include "main.h"

/**
* handlEnvOExit - handles execution of builtin functions
* @command: tokenized commands
* @line: input read from stdin
*
* Return: 1 if executed, 0 if not
*/
int handlEnvOExit(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		printEnv();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		EXIT(command, line);
		return (1);
	}
	return (0);
}
