#include "oussama.h"

/**
 * _strlen - string lengh
 * @a: a
 * Return: b
 */

int _strlen(char *a)
{
	int b = 0;

	while (a[b] != 0)
	{
		b++;
	}
	return (b);
}

/**
 * _strcat - concatenates two strings
 * @a: a
 * @b: b
 * Return: a
 */

char *_strcat(char *a, char *b)
{
	int c = _strlen(a);
	int d = 0;

	while (b[d] != '\0')
	{
		a[c + d] = b[d];
		d++;
	}
	a[c + d] = '\0';
	return (a);
}

/**
* _strncat - concatenate sting to another
* @a: string
* @b: string
* @c: number
* Return: a
*/

char *_strncat(char *a, char *b, int c)
{
	int d = 0;
	int e = _strlen(a);

	while (d < c && b[d] != '\0')
	{
		a[e + d] = b[d];
		d++;
	}
	a[e + d] = '\0';
	return (a);
}

/**
 *_strcmp - compares two strings
 *@a: string
 *@b: string
 * Return: 0
 */

int _strcmp(char *a, char *b)
{
	int c = 0;

	while (a[c] != 0 || b[c] != 0)
	{
		if (a[c] != b[c])
		return (a[c] - b[c]);
		c++;
	}
	return (0);
}

/**
* _strtok - split string
* @a: string
* @b: delim
* Return: d
*/

char *_strtok(char *a, const char *b)
{
	static char *c;
	char *d;

	if (a != NULL)
	{
		c = a;
	}
	else if (c == NULL)
	{
		return (NULL);
	}
	d = c;
	while (*c != '\0')
	{
		if (*b == *c)
		{
			*c = '\0';
			c++;
			return (d);
		}
		c++;
	}
	c = NULL;
	return (d);
}
