/**
 * _strnlen - Find the length of a string.
 * @s: string.
 * Return: length of the string.
 */
int _strnlen(char *s)
{
	int kaa = 0;

	while (*(s + kaa) != '\0')
	{
		kaa++;
	}
	return (kaa);
}

/**
 * _strncatn - Concatenate two strings.
 * @dest: string.
 * @tud: string.
 *
 * Return: Concatenated strings.
 */
char *_strncatn(char *dest, char *tud)
{
	int i;
	int size = _strnlen(dest);

	for (i = 0; tud[i] != '\0'; i++)
	{
		dest[size + i] = tud[i];
	}
	dest[size + i] = '\0';

	return (dest);
}

/**
 * _strncmpr - Compares two strings
 * @s1: string.
 * @s2: string.
 * Return: number < 0 if string 1 less string 2
 *         number = 0 if string 1 is equal to string 2
 *         number > 0 if string 1 is greater than string 2
 */
int _strncmpr(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}


/**
  * _strncpy - Print the same string.
  * @dest: array;
  * @tud: string;.
  *
  * Return: Copied string.
  */
char *_strncpy(char *dest, char *tud)
{
	int j, i = 0;

	while (*(tud + i) != '\0')
	{
		i++;
	}

	for (j = 0; j <= i; j++)
	{
		*(dest + j) = *(tud + j);
	}

	dest[j + 1] = '\0';
	return (dest);
}

/**
  * _strn_byt_cmpr - String byte comaprison.
  * @s1: string 1
  * @s2: string 2
  * @n: number of bytes
  * Return: 0 if equal and 1 if different.
  */
int _strn_byt_cmpr(const char *s1, const char *s2, int n)
{
	unsigned char c1 = '\0';
	unsigned char c2 = '\0';
	int n4;

	if (n >= 4)
	{
		n4 = n >> 2;
		do {
			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
		} while (--n4 > 0);
		n &= 3;
	}
	while (n > 0)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
		n--;
	}
	return (c1 - c2);
}
