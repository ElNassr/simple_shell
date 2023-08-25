#include "main.h"

/**
* TokenizeInput - creates TokenizeInputs from given input
* @line: to be TokenizeInputized
*
* Return: array of strings
*/
char **TokenizeInput(char *line)
{
	char *buf = NULL, *bufp = NULL, *TokenizeInput = NULL, *delim = " :\t\r\n";
	char **TokenizeInputs = NULL;
	int TokenizeInputsize = 1;
	size_t index = 0, flag = 0;

	buf = DuplicateString(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (FindCharacterInString(delim, *bufp) != NULL && flag == 0)
		{
			TokenizeInputsize++;
			flag = 1;
		}
		else if (FindCharacterInString(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	TokenizeInputs = malloc(sizeof(char *) * (TokenizeInputsize + 1));
	TokenizeInput = strtok(buf, delim);
	while (TokenizeInput)
	{
		TokenizeInputs[index] = DuplicateString(TokenizeInput);
		if (TokenizeInputs[index] == NULL)
		{
			free(TokenizeInputs);
			return (NULL);
		}
		TokenizeInput = strtok(NULL, delim);
		index++;
	}
	TokenizeInputs[index] = '\0';
	free(buf);
	return (TokenizeInputs);
}
