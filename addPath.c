#include "main.h"

/**
 * addPath - Construct the
 * ... complete path for a command.
 *
 * This function takes a command and a
 * ... path and creates a complete path by
 * concatenating the path and the command.
 * ... If the command or path is not provided,
 * the function handles it by considering
 * ... an empty string. The resulting complete
 * path is stored in a dynamically
 * ... allocated buffer, which is returned.
 * If memory allocation fails,
 * ... the function returns NULL.
 *
 * @path: Path of the command.
 * @command: User-entered command.
 *
 * Return: Pointer to the buffer containing the
 * ... complete path on success, NULL on failure.
 */
char *addPath(char *path, char *command)
{
    char *buf;
    size_t i = 0, j = 0;

    if (command == 0)
        command = "";

    if (path == 0)
        path = "";

    buf = malloc(sizeof(char) * (GetStringLength(path) + GetStringLength(command) + 2));
    if (!buf)
        return (NULL);

    while (path[i])
    {
        buf[i] = path[i];
        i++;
    }

    if (path[i - 1] != '/')
    {
        buf[i] = '/';
        i++;
    }
    while (command[j])
    {
        buf[i + j] = command[j];
        j++;
    }
    buf[i + j] = '\0';
    return (buf);
}
