#include "main.h"

/**
* main - main function that calls the functions of simple shell
* description : function main
*
* @argc : number of input argumetns
* @argv : string of the arguments
* @envp : environement of the directory
*
* Return: 0 if success
*/

int main(int argc, char *argv[], char *envp[])
{
char *line = NULL, *pathCommand = NULL, *path;
char **Tok = NULL, **paths = NULL;
size_t len = 0;
int read;
(void)envp;

	if (argc < 0)
		return (-1);
	signal(SIGINT, Handler);
	while (1)
	{
		Free(Tok);
		prompt();
		read = getline(&line, &len, stdin);
		if (read < 0)
			break;
		if (line[_strlen(line) - 1] == '\n')
			line[_strlen(line) - 1] = '\0';
		Tok = token(line);
		if (Tok == NULL || *Tok == NULL || **Tok == '\0')
			continue;
		if (ApplyExecute(Tok, line))
			continue;
		path = Path();
		paths = token(path);
		pathCommand = testPath(paths, Tok[0]);
		if (!pathCommand)
			perror(argv[0]);
		else
			execute(pathCommand, Tok);
		Free(paths);
		free(pathCommand);

	}
	free(line);
	return (0);
}
