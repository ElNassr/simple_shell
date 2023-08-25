#include "main.h"

/**
 * _printchar - print character
 *
 * @str : character to be printed
 * @len : length of the character
 *
 */

void _printchar(char *str, ssize_t len)
{
	write(STDOUT_FILENO, str, len);
}
