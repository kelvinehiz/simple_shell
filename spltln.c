#include "main.h"

/**
*_splitln - Split the line wrote in the console.
*@line: Line wrote in console.
*Return: An array with all words splited.
 */
char **_splitln(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("hsh: allocation error\n");
		return (NULL);
	}

	token = _strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = _realloct(tokens, bufsize - 64, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("hsh: allocation error\n");
				return (NULL);
			}
		}
		token = _strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
