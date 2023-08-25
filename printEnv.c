#include "main.h"

/**
* printEnv - prints the environment string to stdout
*
*/
void printEnv(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		_printStr(env[x], _strlen(env[x]));
		_printStr("\n", 1);
		x++;
	}
}
