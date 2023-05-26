#include "oussama.h"

/**
 * num_len - return number len
 * @a: number
 * Return: b
 */

int num_len(int a)
{
	int b = 1;

	pr_numb(a);
	if (a < 0)
	b++;
	while (a /= 10)
	b++;
	return (b);
}

/**
 * pr_char - print char
 * @a: char
 * Return: len
 */

int pr_char(char a)
{
	return (write(2, &a, 1));
}

/**
 * pr_str - print string
 * @a: string
 * Return: len
 */

int pr_str(char *a)
{
	return (write(2, a, _strlen(a)));
}

/**
 * pr_numb - print number
 * @a: number
 */

void pr_numb(int a)
{
	unsigned int b;

	if (a < 0)
	{
		b = -a;
		pr_char('-');
	}
	else
	b = a;
	if (b / 10)
	pr_numb(b / 10);
	pr_char((b % 10) + '0');
}

/**
 * pr_ar - print argument
 * @a: a
 * @ar: args
 * Return: b
 */

int pr_ar(char a, va_list ar)
{
	int b = 0;
	char *str;

	if (a == 'c')
	b += pr_char(va_arg(ar, int));
	else if (a == 's')
	{
		str = va_arg(ar, char *);
		b += pr_str(STRING);
	}
	else if (a == 'i' || a == 'd')
	b += num_len(va_arg(ar, int));
	else if (a == '%')
	b += pr_char('%');
	else
	{
		b += pr_char('%');
		b += pr_char(a);
	}
	return (b);
}
