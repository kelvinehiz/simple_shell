#include "main.h"


/**
  * _splt_pat - Splits the line of the path environment variable.
  * @line: Line which contains the path
  * @copy_line: Copy of the line which contains the path.
  * Return: An array with all paths splited.
  */
char **_splt_pat(char *line, char *copy_line)
{
	int bufsize = 1024, position = 0;
	char **tokens;
	char *token;
	char *delim = ":\r\n\a";

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("hsh: allocation error\n");
		return (NULL);
	}
	_strncpy(copy_line, line);
	if (*copy_line == *delim)
	{
		*copy_line = '\0';
		tokens[position] = copy_line;
/*		printf("%d: %s\n", position, tokens[position]);*/
		position++;
	}
	token = _strtok(copy_line, delim);
	while (token != NULL)
	{
		tokens[position] = token;
/*		printf("%d: %s\n", position, tokens[position]);*/
		position++;

		if (position >= bufsize)
		{
			bufsize += 1024;
			tokens = _realloct(tokens, bufsize - 1024, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("hsh: allocation error\n");
				return (NULL);
			}
		}
		token = _strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
