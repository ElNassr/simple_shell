#include "main.h"

/**
* Free - frees buffers
* @buf: buffer to be freed
*
*/
void Free(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;

	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
