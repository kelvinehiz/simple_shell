 #include "main.h"

/**
*builtin - Redirect to builtin functions.
*@builtin: Redirect to builtin functions.
*Return: 0 if _hlp works, 1 if ext works.
*/

int (*builtin_func[])(char **args, char *input) = {
	&_cd,
	&_hlp,
	&hsh_ext,
	&_envr,
};

/**
*_exqte - Execute builtin process.
*@args: List of arguments passed from parsing.
*@input: Input line for free.
*Return: _launch(args).
*/
int _exqte(char **args, char *input)
{
	char *builtin_str[] = {"cd", "hlp", "ext", "envr"};
	int i;

	if (args[0] == NULL)
		return (1);

	if (_strncmpr(args[0], "setenv") == 0)
		return (_setenvr(args[1], args[2]));

	for (i = 0; i < 4; i++)
	{
		if (_strncmpr(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args, input));
	}
	return (_launch(args));
}
