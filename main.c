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
	signal(SIGINT, SignalHandler);
	while (1)
	{
		FreeBuffers(Tok);
		PrintPrompt();
		read = getline(&line, &len, stdin);
		if (read < 0)
			break;
		if (line[GetStringLength(line) - 1] == '\n')
			line[GetStringLength(line) - 1] = '\0';
		Tok = TokenizeInput(line);
		if (Tok == NULL || *Tok == NULL || **Tok == '\0')
			continue;
		if (ExecuteCommand(Tok, line))
			continue;
		path = FindPath();
		paths = TokenizeInput(path);
		pathCommand = TestAndAppendPath(paths, Tok[0]);
		if (!pathCommand)
			perror(argv[0]);
		else
			ExecuteCmd(pathCommand, Tok);
		FreeBuffers(paths);
		free(pathCommand);

	}
	free(line);
	return (0);
}
