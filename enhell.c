#include "oussama.h"

/**
 * _realloc - change buffer size and copy buffer
 * @a: old buff
 * @os: old buff size
 * @ns: new buff size
 * Return: new buff
*/

void *_realloc(void *a, unsigned int os, unsigned int ns)
{
	char *buff;
	unsigned int b;

	if (ns == os)
	return (a);
	if (ns == 0 && a != NULL)
	{
		free(a);
		return (NULL);
	}
	buff = malloc(ns);
	if (buff == NULL)
	{
		if (a)
		free(a);
		return (NULL);
	}
	if (a == NULL)
	return (buff);
	for (b = 0; b < os && b < ns; b++)
	{
		buff[b] = ((char *) a)[b];
	}
	free(a);
	return (buff);
}

/**
 * hndl_realloc - handle realloc
 * @ar: parameter of type bruh
 * @buff: buff
 * @buff_size: buff size
 * @a: size
 * @b: number to compare buff size
 * Return: buff
 */

char *hndl_realloc(bruh *ar, char *buff, int *buff_size, int a, int b)
{
	if (*buff_size <= b)
	{
		buff = _realloc(buff, *buff_size, *buff_size + a);
		if (buff == NULL)
		{
			free_ex(ar);
		}
		*buff_size += a;
	}
	return (buff);
}

/**
 * _atoi - convert string to int
 * @a: string
 * Return: d
 */

int _atoi(char *a)
{
	int b = (_strlen(a) - 1);
	int c;
	int d = 0;
	int e = 1;

	for (c = 0; c <= b; c++)
	{
		if (a[b - c] > 47 && a[b - c] < 58)
		{
			d += (a[b - c] - 48) * e;
			e *= 10;
		}
		else
		return (-1);
	}
	return (d);
}

/**
 * g_env - get  environment
 * @a: a
 * @b: b
 * @c: c
 * Return: NULL if...
*/

char *g_env(char **a, char *b, int c)
{
	int d;

	for (d = 0; a[d] != NULL; d++)
	{
		if (_strncmp(a[d], b, c) == 0)
		return (&a[d][c + 1]);
	}
	return (NULL);
}

/**
 * _environ - check if input is env
 * @ar: parameter of type bruh
 * Return: 1 if env, 0 if not
*/

int _environ(bruh *ar)
{
	int a;

	if (rev_comp(ar->ln, "env"))
	{
		for (a = 0; ar->evp[a] != NULL; a++)
		{
			write(1, ar->evp[a], _strlen(ar->evp[a]));
			write(1, "\n", 1);
		}
		ar->sts = 0;
		return (1);
	}
	return (0);
}
