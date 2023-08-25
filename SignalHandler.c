#include "main.h"

/**
 * SignalHandler - Handle Linux signals.
 *
 * This function is a signal handler that
 * ... is called when a specific signal is received.
 * It takes an integer signal number as input
 * ... but does not perform any specific action.
 * Instead, it prints a newline character and a
 * ... PrintPrompt indicating the shell is ready for input.
 *
 * @signal_num: Integer representing the signal number.
 */
void SignalHandler(int signal_num)
{
    (void)signal_num;
    _printchar("\n", 1);
    _printchar("$ ", 2);
}
