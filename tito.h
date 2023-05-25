#ifndef TITO_H
#define TITO_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#define MAX_C 10
/**
 * struct denum - structure that contains vars
 * @cnt: lines cnt
 */
typedef struct denum
{
	int cnt;
} denum;
void prompt(char **arv, char **envp, bool flg);
int strcmp(char *s1, char *s2);
void exit(char *cmd);
void runcmd(char **rgv, char **arv, char **envp);
char *tito(char *cmd);
char *_strncpy(char *pep, char *src, int n);
char *dtr(char *pep, char *src);
char *path(char **rgv, char *cmd);
char *_strcpy(char *pep, char *src);
int _strlen(char *s);
void geterror(denum *n, char **arv, char *cmd);

#endif
