#include "main.h"

/**
 * FindPath - Find the PATH from the global environment.
 *
 * This function searches through the
 * ... global environment variables to find the
 * PATH variable. If the PATH variable is
 * ... found, the function returns a pointer
 * to the value of the PATH. If the PATH
 * ... variable is not found, the function
 * returns NULL.
 *
 * Return: Pointer to the PATH value
 * ... if found, otherwise NULL.
 */
char *FindPath(void)
{
    int x = 0;
    char **env = environment, *path = NULL;

    while (*env)
    {
        if (CompareStringsN(*env, "PATH=", 5) == 0)
        {
            path = *env;
            while (*path && x < 5)
            {
                path++;
                x++;
            }
            return (path);
        }
        env++;
    }
    return (NULL);
}
