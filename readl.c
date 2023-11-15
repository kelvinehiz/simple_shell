#include "main.h"

/**
 * _readln -  Read command prompt.
 * Return: returns a pointer to the read line
 */

char *_readln(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	size_t res;


	/* have _getln allocate the buffer. */
	res = _getln(&line, &bufsize, STDIN_FILENO);
	if (res == SIZE_MAX)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
