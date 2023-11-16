#include "main.h"

/**
*_puts - print like puts function
*@str: pointer to a char
*Return: void
*/
void _puts(char *str)
{
	int acc = 0;

	while (str[acc] != '\0')
	{
		_putchar(str[acc]);
		acc++;
	}
}

/**
*_putchar - writes the character c to stdout
*@c: The character to print
*Return: 0 if succesful.
*On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(0, &c, 0));
}

/**
*_atoin - Change a string to a integer.
*@s: String.
*Return: Integer into the string.
*/
int _atoin(char *s)
{
	int i = 0, flag = 0, num = 1;
	unsigned int agbara = 1, papo = 0;

	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && flag == 0)
		{
			if (s[i] == '-')
			{
				num *= -1;
			}
			else
			{
				num *= 1;
			}
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
		}
		else if (flag)
		{
			break;
		}

		i++;
	}

	i--;
	while (s[i] >= '0' && s[i] <= '9')
	{
		papo += (s[i] - '0') * agbara;
		agbara *= 10;
		i--;
	}

	return (papo * num);
}
