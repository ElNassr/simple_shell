#include "main.h"

/**
 * FreeBuffers - Free allocated buffers.
 *
 * This function is responsible for
  * ... freeing the memory allocated for a
 * double-pointer buffer. It iterates through
 * ... the array of pointers and frees
 * each individual pointer before
 * ... freeing the array itself. If the input buffer
 * or any of its elements is NULL,
 * ... the function does nothing.
 *
 * @buffer: The double-pointer buffer to be freed.
 */
void FreeBuffers(char **buffer)
{
    int i = 0;

    if (!buffer || buffer == NULL)
        return;

    while (buffer[i])
    {
        free(buffer[i]);
        i++;
    }
    free(buffer);
}
