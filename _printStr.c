#include "main.h"

/**
 * _printStr - print string
 *
 * @str : strings to be printed
 * @len : length of the string
 *
 */

void _printStr(char *str, ssize_t len)
{
	write(STDOUT_FILENO, str, len);
}
