#include "main.h"

/**
 * ExecuteCommand - Check and execute built-in or external commands.
 *
 * This function examines the user input
 * ... command and determines whether it is a
 * built-in function like "exit" or "env,"
 * ... or an external command located in a
 * specific directory. If the command is
 * ... recognized as a built-in function,
 * it is executed, and the function returns 1.
 * ... If it's an external command,
 * the function attempts to execute it
 * ... and returns 1. If neither condition
 * ... is met, the function returns 0.
 *
 * @cmd: Tokenized user input representing
 * ... the command and its arguments.
 * @buf: The input line retrieved using
 * ... the getline function.
 *
 * Return: 1 if the command is executed, 0 otherwise.
 */
int ExecuteCommand(char **cmd, char *buf)
{
    if (HandleEnvOrExit(cmd, buf))
        return (1);
    else if (**cmd == '/')
    {
        ExecuteCmd(cmd[0], cmd);
        return (1);
    }
    return (0);
}

