#ifndef _OUSSAMA_H_
#define _OUSSAMA_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define STRING ((str) ? str : "(null)")

/**
 * struct bruh - structure
 * @shll_nm: name of shell
 * @evp: array of environment
 * @ln: input
 * @pwd: working directory
 * @opwd: old dir
 * @pth: path
 * @npth: number of token in path
 * @ntk: number of token
 * @cnt: count
 * @sts: status
 * @fl: file
 * @pid: id
 */

typedef struct bruh
{
	char **pwd;
	char **evp;
	char *ln;
	char *shll_nm;
	char *pth;
	char *opwd;
	int ntk;
	int npth;
	int sts;
	int cnt;
	int fl;
	int pid;
} bruh;

ssize_t _getline(bruh *ar);

int _atoi(char *a);
int cd(bruh *ar);
int _cmnd_(bruh *ar);
int _excev(bruh *ar, char *buff);
int _exit_(bruh *ar);
int main(int arc, char **arv, char **evp);
int _printf(const char *a, ...);
int tkn(char *a, char *b);
int _environ(bruh *ar);
int pr_ar(char a, va_list ar);
int pr_str(char *a);
int pr_char(char a);
int num_len(int a);
int hndl_input(bruh *ar);
int input(bruh *ar, int a, int *b);
int _strcmp(char *a, char *b);
int _strlen(char *a);
int _strncmp(const char *a, const char *b, size_t c);
int rev_comp(char *a, char *b);


void numchange(char *a, int b);
void hndl_money(char *a, char **d, bruh *ar);
void pr_numb(int a);
void *_realloc(void *a, unsigned int os, unsigned int ns);
void ctrl_c(int c);
void hndl_point(char **line, bruh *ar);
void free_ex(bruh *ar);
void chng_pwd(bruh *ar);
void emptyy(char **a, bruh *ar);


char **g_PWD(bruh *ar);
char *g_env(char **a, char *b, int c);
char *_malloc(bruh *ar, int a);
char *malloctoo(char *line, bruh *ar, int a);
char *hndl_realloc(bruh *ar, char *buff, int *buff_size, int a, int b);
char *_strchr(char *a, char b);
char *_strtok(char *a, const char *b);
char *_strncat(char *a, char *b, int c);
char *_strcat(char *a, char *b);
char *_strdup(bruh *ar, char *a);

#endif
