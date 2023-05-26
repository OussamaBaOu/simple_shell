#include "oussama.h"

/**
 * _cmnd_ - handle path of command
 * @ar: parameter of type bruh
 * Return: 0 or 127
 */

int _cmnd_(bruh *ar)
{
	int i;
	char *pth = ar->pth;

	if (_exit_(ar) || cd(ar))
	return (ar->sts);
	if (ar->ln[0] == '/')
	{
		if (access(ar->ln, X_OK) == 0)
		{
			if (!_environ(ar))
			return (_excev(ar, ar->ln));
			return (0);
		}
		_printf("%s: %i: %s: not found\n", ar->shll_nm, ar->cnt, ar->ln);
	}
	else
	{
		if (!_strcmp(ar->ln, "env") && _environ(ar))
		return (0);
		for (i = 0; i < ar->npth; i++)
		{
			char buffer[500] = "";

			_strcat(buffer, pth);
			_strcat(buffer, "/");
			_strcat(buffer, ar->ln);
			if (access(buffer, X_OK) == 0)
			return (_excev(ar, buffer));
			pth += _strlen(pth) + 1;
		}
		_printf("%s: %i: %s: not found\n", ar->shll_nm, ar->cnt, ar->ln);
	}
	ar->sts = 127;
	return (127);
}

/**
* _excev - executing command
* @ar: parameter of type bruh
* @buff: input buffer
* Return: status
*/

int _excev(bruh *ar, char *buff)
{
	int i;
	char **arv;
	char *ln = ar->ln;
	pid_t id = fork();

	if (!id)
	{
		if (rev_comp(ar->ln, "pwd"))
		{
			arv = malloc(16);
			if (arv == NULL)
			exit(255);
			arv[0] = ar->ln;
			arv[1] = NULL;
		}
		else
		{
			arv = malloc(8 * (ar->ntk + 1));
			if (arv == NULL)
			exit(255);
			for (i = 0; i < ar->ntk; i++)
			{
				arv[i] = ln;
				ln += _strlen(ln) + 1;
			}
			arv[i] = NULL;
		}
		execve(buff, arv, NULL);
		free(arv);
		exit(ar->sts);
	}
	wait(&(ar->sts));
	ar->sts = WEXITSTATUS(ar->sts);
	return (ar->sts);
}

/**
 * _exit_ - handle exit shell and exit status
 * @ar: parameter of type bruh
 * Return: 0 success, 1 fail
*/

int _exit_(bruh *ar)
{
	int a;

	if (!_strcmp(ar->ln, "exit"))
	{
		if (ar->ntk > 1)
		{
			a = _strlen(ar->ln) + 1;
			ar->sts = _atoi(ar->ln + a);
		}
		if (ar->sts != -1)
		{
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
		_printf("%s: %i: exit: bad number: %s\n",
		ar->shll_nm, ar->cnt, ar->ln + a);
		ar->sts = 2;
		return (1);
	}
	return (0);
}

/**
* ctrl_c - handle signal
* @c: signal
*/

void ctrl_c(int c)
{
	if (c == SIGINT)
	{
		write(1, "\noussama$ ", 10);
	}
}

/**
* main - main
* @arc: arg c
* @arv: arg v
* @evp: array of environment variable
* Return: 0
*/

int main(int arc, char **arv, char **evp)
{
	bruh ar;
	int a = 1, b = 0;

	ar.ln = NULL, ar.pth = NULL;
	ar.evp = evp;
	ar.pwd = NULL;
	ar.opwd = NULL;
	ar.pth = _strdup(&ar, g_env(evp, "PATH", 4));
	ar.pwd = g_PWD(&ar);
	if (ar.pwd)
	ar.opwd = _strdup(&ar, &((*ar.pwd)[4]));
	ar.shll_nm = arv[0];
	ar.cnt = 0, ar.sts = 0, ar.fl = 0;
	ar.pid = (int)getpid();
	ar.npth = tkn(ar.pth, ":");
	if (arc > 1)
	{
		ar.fl = open(arv[1], O_RDONLY);
		if (ar.fl == -1)
		{
			_printf("%s: 0: cannot open %s: no such file\n", arv[0], arv[1]);
			free_ex(&ar);
			exit(2);
		}
	}
	while (1)
	{
		if (isatty(STDIN_FILENO) && a && !ar.fl)
		write(1, "oussama$ ", 9);
		signal(SIGINT, ctrl_c);
		ar.cnt++;
		a = input(&ar, a, &b);
		if (hndl_input(&ar))
		continue;
		ar.ntk = tkn(ar.ln, " ");
		if (_cmnd_(&ar) == 255)
		free_ex(&ar);
	}
	return (0);
}
