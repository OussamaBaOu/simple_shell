#include "oussama.h"

/**
* _strdup - return pointer to space contain copy of string
* @a: string
* @ar: parameter of type bruh
* Return: d
*/

char *_strdup(bruh *ar, char *a)
{
	int b;
	int c;
	char *d;

	if (!a)
	return (NULL);
	c = _strlen(a);
	d = _malloc(ar, c + 1);
	for (b = 0; b <= c; b++)
	{
		d[b] = a[b];
	}
	return (d);
}

/**
* _strncmp - compare c bytes of a and b
* @a: string
* @b: string
* @c: number
* Return: 0 if strings equal.
*/

int _strncmp(const char *a, const char *b, size_t c)
{
	while (c-- && (*a != '\0' || *b != '\0'))
	{
		if (*a != *b)
		return (*a - *b);
		a++;
		b++;
	}
	return (0);
}

/**
* _strchr - locate char in string
* @a: string
* @b: char
* Return: NULL if...
*/

char *_strchr(char *a, char b)
{
	int c = 0;

	while (c < _strlen(a))
	{
		if (a[c] == b)
		{
			return (a + c);
		}
		c++;
	}
	return (NULL);
}

/**
 * numchange - change number into string
 * @a: .
 * @b: .
*/

void numchange(char *a, int b)
{
	int d;
	int c = 0;
	int e = b;

	if (!e)
	{
		a[0] = '0';
		a[1] = '\0';
		return;
	}
	while (e)
	{
		c++;
		e /= 10;
	}
	for (d = 0; d < c; d++)
	{
		a[c - (d + 1)] = b % 10 + '0';
		b /= 10;
	}
	a[c] = '\0';
}

/**
 * rev_comp - compare strings backward
 * @a: string
 * @b: string
 * Return: 1 success, 0 fail
*/

int rev_comp(char *a, char *b)
{
	int c;
	int d = (_strlen(a) - 1);
	int e = (_strlen(b) - 1);

	if (e > d)
	return (0);
	for (c = e; c >= 0; c--)
	{
		if (a[d] != b[c])
		return (0);
		d--;
	}
	return (1);
}
