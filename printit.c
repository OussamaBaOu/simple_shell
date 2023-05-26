#include "oussama.h"

/**
 * _printf - printf
 * @a: a
 * Return: c
 */

int _printf(const char *a, ...)
{
	unsigned int b;
	unsigned int c = 0;
	va_list ar;

	if (a == NULL)
	return (-1);
	va_start(ar, a);
	for (b = 0; a[b]; b++)
	{
		if (a[b] != '%')
		{
			c += pr_char(a[b]);
			continue;
		}
		if ((int)b++ == _strlen((char *)a) - 1)
		return (-1);
		c += pr_ar(a[b], ar);
	}
	va_end(ar);
	return (c);
}

/**
 * hndl_point - handle point
 * @ln: input
 * @ar: parameter of type bruh
 */

void hndl_point(char **ln, bruh *ar)
{
	int a = 0;
	int b;
	char *c = *ln;
	char *buff;

	if (c[0] == '.')
	{
		buff = malloctoo(*ln, ar, 512);
		buff[0] = '\0';
		_strcat(buff, &((*(ar->pwd))[4]));
		b = _strlen(buff);
		while (c[a] && c[a] != ' ')
		{
			if (c[a] == '.' && c[a + 1] == '.')
			{
				while (buff[b - 1] != '/')
				buff[(b--) - 1] = '\0';
				buff[(b--) - 1] = '\0';
				a++;
			}
			else if (c[a] != '/' && c[a] != '.')
			{
				buff[b++] = '/';
				while (c[a] && c[a] != '/' && c[a] != ' ')
				buff[b++] = c[a++];
				a--;
			}
			a++;
		}
		buff[b] = '\0';
		if (access(buff, X_OK) == 0)
		{
			_strcat(buff, &c[a]);
			free(*ln);
			*ln = buff;
		}
	}
}

/**
 * _malloc - handle malloc
 * @ar: parameter of type bruh
 * @a: size
 * Return: buff
 */

char *_malloc(bruh *ar, int a)
{
	char *buff = malloc(a);

	if (!buff)
	free_ex(ar);
	return (buff);
}

/**
 * malloctoo - handle malloc too
 * @ln: input
 * @ar: parameter of type bruh
 * @a: size
 * Return: buff
 */

char *malloctoo(char *ln, bruh *ar, int a)
{
	char *buff = malloc(a);

	if (!buff)
	{
		free(ln);
		free_ex(ar);
	}
	return (buff);
}

/**
* tkn - return splitted number
* @a: string
* @b: delim
* Return: c
*/

int tkn(char *a, char *b)
{
	int c = 0;
	char *d = _strtok(a, b);

	while (d)
	{
		d = _strtok(NULL, b);
		c++;
	}
	return (c);
}
