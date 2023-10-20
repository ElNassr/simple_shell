#include "main.h"

/**
* prompt - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
* Return: no return
*/
void prompt(void)
{

	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		_printStr("$ ", 2);
}
