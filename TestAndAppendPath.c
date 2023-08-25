#include "main.h"

/**
 * TestAndAppendPath - Test the validity
 * ... of paths and append a command.
 *
 * This function tests the validity
 * ... of each path in the `path` array by
 * appending the `command` to it and
 * ... checking if the resulting path is executable.
 * It iterates through each path in the
 * ... `path` array and appends the `command`.
 * If an executable path is found, it is
 * ... returned. If no valid path is found,
 * the function returns NULL.
 *
 * @path: Array of TokenizeInputized paths.
 * @command: User-entered command.
 *
 * Return: Executable path appended with
 * ... command on success, otherwise NULL.
 */
char *TestAndAppendPath(char **path, char *command)
{
    int i = 0;
    char *output;

    while (path[i])
    {
        output = CreateCompletePath(path[i], command);
        if (access(output, F_OK | X_OK) == 0)
            return (output);
        free(output);
        i++;
    }
    return (NULL);
}
