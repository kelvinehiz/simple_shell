nclude "main.h"
/**
*_getenvr - Find a variable in all environment variables.
*@name: Name of the environment variable.
*Return: All the content into the environment variable.
*/

char *_getenvr(const char *name)
{
	size_t len;
	char **ep;

	/* Get NAME length*/
	len = _strnlen((char *)name);


	if (environ == NULL || name[0] == '\0')
		return (NULL);

	len--;
	for (ep = environ; *ep != NULL; ep++)
	{
		if (!_strn_byt_cmpr(*ep, name, len) && (*ep)[len + 1] == '=')
			return (&(*ep)[len + 2]);
	}
	return (NULL);
}
