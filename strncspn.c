#include "main.h"

/**
*_strncspn - Find the positing where the delim is found in the string.
*@s: String.
*@delim: Delimiter.
*Return: the position in the string.
*/
int _strncspn(char *s, const char *delim)
{
	int counter = 0, i;

	while (*s)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*s == delim[i])
				return (counter);
		}
		counter++;
		s++;
	}
	return (counter);
}

/**
*_strnspn - Find the positing until the delim is equal to the string.
*@s: String.
*@delim: Delimiter.
*Return: the position when delim is different to the string.
*/

int _strnspn(char *s, const char *delim)
{
	int i;

	for (i = 0; (s[i] == delim[i]) && (s[i] != '\0' && delim[i] != '\0'); i++)
	{
		;
	}
	return (i);
}
/**
*_strtok_r - Find the first token in a string until the dilimiter
*and save the rest of the string in save_str.
*@s: String.
*@delim: Delimiter.
*@save_str: The rest of the string.
*Return: First word tokenized.
*/
char *_strtok_r(char *s, const char *delim, char **save_str)
{
	char *end;

	if (s == NULL)
	s = *save_str;

	if (*s == '\0')
	{
		*save_str = s;
		return (NULL);
	}

	s += _strnspn(s, delim);

	if (*s == '\0')
	{
		*save_str = s;
		return (NULL);
	}
	end = s + _strncspn(s, delim);

	if (*end == '\0')
	{
		*save_str = end;
		return (s);
	}

	*end = '\0';
	*save_str = end + 1;
	return (s);
}
/**
*_strtok - Tokenize a string in words separated by a delimiter.
*@s: String.
*@delim: Delimiter.
*Return: Word tekenized.
*/

char *_strtok(char *s, const char *delim)
{
	static char *olds;

	return (_strtok_r(s, delim, &olds));
}
