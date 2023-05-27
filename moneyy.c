#include "oussama.h"
#define D(i) (*d)[i]

/**
 * hndl_money - handle input $
 * @a: input
 * @d: input
 * @ar: parameter of type bruh
 */

void hndl_money(char *a, char **d, bruh *ar)
{
	char m[10];
	char *b;
	int c = 0;

	(*d)++;
	if (D(0) == '$' || D(0) == '?')
	{
		if (D(0) == '$')
		numchange(m, ar->pid);
		else
		numchange(m, ar->sts);
		_strcat(a, m);
		(*d)++;
	}
	else
	{
		while (D(c) && D(c) != ' ' && D(c) != '#' && D(c) != '$' && D(c) != '/')
		c++;
		if (!c)
		_strcat(a, "$");
		else
		{
			b = g_env(ar->evp, *d, c);
			if (b)
			_strcat(a, b);
			*d += c;
		}
	}
}

/**
 * hndl_input - determine if line contain $ or #
 * @ar: parameter of type bruh.
 * Return: 1 if the string is empty
 */

int hndl_input(bruh *ar)
{
	char *buff;
	char *a;
	char *b;
	char *c = _strchr(ar->ln, '#');
	int buff_size = 10000;

	if (c && ((c != ar->ln && *(c - 1) == ' ') || c == ar->ln))
	*c = '\0';
	buff = _malloc(ar, buff_size);
	a = _strchr(ar->ln, '$');
	b = ar->ln;
	buff[0] = '\0';
	while (a)
	{
		buff = hndl_realloc(ar, buff, &buff_size, 1024, _strlen(buff) + a - b);
		_strncat(buff, b, a - b);
		hndl_money(buff, &a, ar);
		b = a;
		a = _strchr(b, '$');
	}
	buff = hndl_realloc(ar, buff, &buff_size, 128, _strlen(buff) + _strlen(b));
	_strcat(buff, b);
	emptyy(&buff, ar);
	hndl_point(&buff, ar);
	free(ar->ln);
	ar->ln = buff;
	return (buff[0] == '\0');
}

/**
 * input - determine if we start new line in shell
 * @ar: parameter of type bruh
 * @a: 1 if stdin
 * @b:  0 or 1
 * Return: 0, 1
 */

int input(bruh *ar, int a, int *b)
{
	ssize_t c;

	c = _getline(ar);
	if (c == -1)
	{
		if (isatty(STDIN_FILENO) && a && !ar->fl)
		write(1, "\n", 1);
		close(ar->fl);
		if (ar->ln)
		free(ar->ln);
		if (ar->pth)
		free(ar->pth);
		if (ar->pwd)
		free(*(ar->pwd));
		if (ar->opwd)
		free(ar->opwd);
		exit(ar->sts);
	}
	if (*b)
	ar->cnt--;
	if (ar->ln[c - 1] == '\n')
	{
		ar->ln[c - 1] = '\0';
	}
	if (ar->ln[c - 1] == ';')
	{
		ar->ln[c - 1] = '\0';
		*b = 1;
		return (0);
	}
	*b = 0;
	return (1);
}

/**
 * emptyy - handle extra space in input
 * @a: input
 * @ar: parameter of type bruh
 */

void emptyy(char **a, bruh *ar)
{
	int b = 0;
	int c = 0;
	char *buff = malloc(_strlen(*a) + 1);

	if (buff == NULL)
	{
		free(*a);
		free_ex(ar);
	}
	while ((*a)[b] && (*a)[b] == ' ')
	b++;
	while ((*a)[b])
	{
		if ((*a)[b] == ' ')
		{
			buff[c] = ' ';
			c++;
			while ((*a)[b] == ' ')
			b++;
		}
		else
		{
			buff[c] = (*a)[b];
			b++;
			c++;
		}
	}
	if (c && buff[c - 1] == ' ')
	c--;
	buff[c] = '\0';
	free(*a);
	*a = buff;
}

/**
 * _getline - read entire line
 * @ar: parameter of type bruh
 * Return: a
 */

ssize_t _getline(bruh *ar)
{
	size_t a = 0;
	ssize_t b;
	char *buff;
	int buff_size = 10000;

	if (&(ar->ln) == NULL)
	return (-1);
	buff = _malloc(ar, buff_size + 1);
	if (ar->ln)
	{
		free(ar->ln);
		ar->ln = NULL;
	}
	while ((b = read(ar->fl, buff + a, 1)) > 0)
	{
		a++;
		buff = hndl_realloc(ar, buff, &buff_size, 1024, a);
		if (buff[a - 1] == '\n' || buff[a - 1] == ';')
		break;
	}
	if (b < 0 || (!b && !a))
	{
		free(buff);
		return (-1);
	}
	if (b != 8)
	buff[a] = '\0';
	ar->ln = buff;
	return (a);
}
