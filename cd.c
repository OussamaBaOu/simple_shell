#include "oussama.h"

/**
 * cd - change dir
 * @ar: parameter of type bruh
 * Return: 0
 */

int cd(bruh *ar)
{
	char *a;
	char *ln = ar->ln;

	if (!_strcmp(ln, "cd"))
	{
		if (ar->ntk == 1)
		a = g_env(ar->evp, "HOME", 4);
		else
		{
			ln += 3;
			if (!_strcmp(ln, "-"))
			{
				a = ar->opwd;
				write(1, a, _strlen(a));
				write(1, "\n", 1);
			}
			else
			a = ln;
		}
		if (chdir(a) == -1)
		{
			_printf("%s: %i: cd: can't cd to %s\n", ar->shll_nm, ar->cnt, a);
			ar->sts = 2;
		}
		else
		{
			free(ar->opwd);
			ar->opwd = _strdup(ar, &((*(ar->pwd))[4]));
			if (!ar->opwd)
			free_ex(ar);
			chng_pwd(ar);
			ar->sts = 0;
		}
		return (1);
	}
	return (0);
}

/**
 * g_PWD - get pwd from  env
 * @ar: parameter of type bruh
 * Return: NULL
 */

char **g_PWD(bruh *ar)
{
	int a;
	char *pwd = NULL;

	for (a = 0; ar->evp[a] != NULL; a++)
	{
		if (_strncmp(ar->evp[a], "PWD", 3) == 0)
		{
			pwd = _strdup(ar, ar->evp[a]);
			ar->evp[a] = pwd;
			return (&(ar->evp[a]));
		}
	}
	return (NULL);
}

/**
 * chng_pwd - change pwd
 * @ar: parameter of type bruh.
 */

void chng_pwd(bruh *ar)
{
	char buff[250];
	char *pwd = _malloc(ar, 256);

	getcwd(buff, 250);
	pwd[0] = '\0';
	_strcat(pwd, "PWD=");
	_strcat(pwd, buff);
	free(*(ar->pwd));
	*(ar->pwd) = pwd;
}

/**
 * free_ex - free ar before exit
 * @ar: parameter of type bruh
 */

void free_ex(bruh *ar)
{
	if (ar->ln)
	{
	free(ar->ln);
	}
	if (ar->pth)
	{
		free(ar->pth);
	}
	if (ar->pwd)
	{
		free(*(ar->pwd));
	}
	if (ar->opwd)
	{
		free(ar->opwd);
	}
	exit(2);
}
