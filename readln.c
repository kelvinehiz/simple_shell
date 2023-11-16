#include "main.h"

/**
   * readln - reads the input string.
    *
     * @r_vgf: returns value of getline function
      * Return: input string
       */
char *readln(int *r_vgf)
{
	char *input = NULL;
	size_t bufsize = 0;

	*r_vgf = getline(&input, &bufsize, stdin);

	return (input);
}
