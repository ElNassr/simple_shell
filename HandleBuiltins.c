#include "main.h"

/**
 * HandleBuiltins - Handle the execution of built-in functions.
 *
 * This function handles the execution of built-in commands like "env" and "exit".
 * It checks if the provided `command` matches any of the built-in commands and
 * performs the corresponding action. If the command is a built-in and is executed,
 * the function returns 1; otherwise, it returns 0.
 *
 * @command: Array of tokenized commands.
 * @line: Input read from stdin.
 *
 * Return: 1 if a built-in command was executed, 0 if not.
 */
int HandleBuiltins(char **command, char *line)
{
    struct builtin builtin = {"env", "exit"};

    if (CompareStrings(*command, builtin.env) == 0)
    {
        PrintEnvironment();
        return (1);
    }
    else if (CompareStrings(*command, builtin.exit) == 0)
    {
        HandleExit(command, line);
        return (1);
    }
    return (0);
}
