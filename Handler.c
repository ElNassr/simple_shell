#include "main.h"

/**
 * Handler - function that handle linux signales
 *
 * @num: int as inpu signalet
 */

void Handler(int num)
{
	(void)num;
	_printStr("\n", 1);
	_printStr("$ ", 2);
}
