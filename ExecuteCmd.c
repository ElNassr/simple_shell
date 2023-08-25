#include "main.h"

/**
 * ExecuteCmd - Execute a given command with arguments.
 *
 * This function takes a command and
 * ... an array of arguments and executes the
 * command using the `execve` function.
 * ... The function first forks a child process
 * and attempts to execute the given
 * ... command within that child process. If the
 * command execution fails, an error
 * ... message is displayed, and the child process
 * exits with status 98. The parent
 * ... process waits for the child process to
 * complete before proceeding.
 * ... The environment variables are also passed to the
 * executed command.
 *
 * @command: Command to be executed.
 * @args: Array of arguments for the command.
 */
void ExecuteCmd(char *command, char **args)
{
    pid_t child_pid;
    int status;
    char **env = environment;

    child_pid = fork();
    if (child_pid < 0)
        perror(command);
    if (child_pid == 0)
    {
        execve(command, args, env);
        perror(command);
        free(command);
        FreeBuffers(args); /* Assuming this is your own function to free memory */
        exit(98);
    }
    else
        wait(&status);
}
