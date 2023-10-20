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
extern char **environ;

/* string handlers */
ssize_t _strcmp(char *s1, char *s2);
ssize_t _strlen(char *s);
ssize_t _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);
void execution(char *cp, char **cmd);
char *find_path(void);

/* Function of simple shell */
/* --------------------------------------- */

/* execute instruction */
void execute(char *cp, char **cmd);
/* free pointer */
void Free(char **buf);
/* print */
void _printStr(char *str, ssize_t len);
/* READLINE */
char *Readline(void);
/* exit */
void EXIT(char **command, char *line);
/* token */
char **token(char *line);
/* check if  print env or exit else apply execute */
int ApplyExecute(char **cmd, char *buf);
/* if env print env and if exit exit prog */
int handlEnvOExit(char **command, char *line);
/* print envioronment */
void printEnv(void);
/* test if path exist and execute */
char *testPath(char **path, char *command);
/* place your path on the path from enviorenment */
char *completePath(char *path, char *command);
/* find path from eviorenement */
char *Path(void);
/* signal handling of ctr + c */
void Handler(int num);
/* test if interactive mode */
void prompt(void);

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
