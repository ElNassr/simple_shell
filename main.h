#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environment;

/* string handlers */
ssize_t CompareStrings(char *s1, char *s2);
ssize_t GetStringLength(char *s);
ssize_t CompareStringsN(char *s1, char *s2, int n);
char *DuplicateString(char *s);
char *FindCharacterInString(char *s, char c);
void execution(char *cp, char **cmd);
char *find_path(void);

/* Function of simple shell */
/* --------------------------------------- */

/* execute instruction */
void ExecuteCmd(char *cp, char **cmd);
/* free pointer */
void FreeBuffers(char **buf);
/* print */
void _printchar(char *str, ssize_t len);
/* READLINE */
char *Readline(void);
/* exit */
void HandleExit(char **command, char *line);
/* TokenizeInput */
char **TokenizeInput(char *line);
/* check if  print env or exit else apply execute */
int ExecuteCommand(char **cmd, char *buf);
/* test if path exist and execute */
char *TestAndAppendPath(char **path, char *command);
/* place your path on the path from enviorenment */
char *addPath(char *path, char *command);
/* find path from eviorenement */
char *FindPath(void);
/* signal handling of ctr + c */
void SignalHandler(int num);
/* test if interactive mode */
void PrintPrompt(void);

/* -------------------------------------- */
/**
* struct builtin - builtin
* @env : envirenment
* @exit : exit func
*/
typedef struct builtin
{
	char *env;
	char *exit;
} builtin;


#endif /* SHELL_H */
