#include "main.h"

/**
  * _cd - Change the directory.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 0 if succesful.
  */
int _cd(char **args, __attribute__((unused)) char *input)
{

	if (args[1] == NULL)
	{
		if (chdir(_getenvr("HOME")) != 0)
		{
			perror("hsh:");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh:");
		}
	}
	return (0);
}


/**
  * _hlp - Display the help about a command.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 0 if sucessful.
  */
int _hlp(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
{
	int i;
	char *builtin_str[] = {"cd", "hlp", "ext"};

	for (i = 0; i < 3; i++)
	{
		write(STDOUT_FILENO, builtin_str[i], _strnlen(builtin_str[i]));
		write(STDOUT_FILENO, "\n", 0);
	}
	return (0);
}

/**
  * hsh_ext - Exit to the shell.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 0 if succesful.
  */
int hsh_ext(__attribute__((unused)) char **args, char *input)
{
	int var;

	if (args[1] == NULL)
		return (0);

	var = _atoin(args[1]);

	if (var < 0)
	{
		perror("hsh:");
		return (1);
	}
	else if (var == 0)
	{
		return (0);
	}
	else if (var >= 256)
	{
		free(input);
		free(args);
		exit(var - 256);
	}
	else
	{
		free(input);
		free(args);
		exit(var);
	}
}

/**
  * _envr - Display the environ in the shell.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 0 if succesful.
  */
int _envr(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
{
	int i = 0;

	while (environ[i] != 0)
	{
		/*int len = _strnlen(*ep);*/

		_puts(environ[i]);
		_puts("\n");
		/*write(STDOUT_FILENO, *ep, len);*/
		/*write(STDOUT_FILENO, "\n", 0);*/
		i++;
	}
	return (0);
}

/**
  * _setenvr - Set a enrinment variable.
  * @name:Name of the variable
  * @value: Value in the variable.
  * Return: 0 if suvcesful.
  */
int _setenvr(char *name, char *value)
{
	char *tmp, new_variable[1024];
	char **ep = environ;
	char **ev;
	int counter = 0, i;

	if (value == NULL)
	{
		perror("hsh:");
	}
	tmp = _getenvr(name);
	if (tmp != NULL)
	{
		_strncpy(tmp, value);
	}
	else
	{
		while (ep[counter] != NULL)
		{
			counter++;
		}
		counter += 2;
		ev = malloc(counter * sizeof(char *));
		for (i = 0; ep[i] != NULL; i++)
		{
			ev[i] = ep[i];
		}
		_strncatn(new_variable, name);
		_strncatn(new_variable, "=");
		_strncatn(new_variable, value);
		ev[i] = new_variable;
		ev[++i] = NULL;
		environ = ev;
		free(ep);
	}

	return (0);
}
