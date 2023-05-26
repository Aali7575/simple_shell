#ifndef TITUS_H
#define TITUS_H
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
void prompt(char **abc, char **envp, bool flg);
int _strcmp(char *t1, char *t2);
char *_strcat(char *pest, char *src);
char *pathhandler(char **rgv, char *cmd);
char *strcpyy(char *pest, char *src);
int _strlen(char *s);
void exitt(char *cmd);
void runcmd(char **rgv, char **abc, char **envp);
char *trim(char *cmd);
char *strncopy(char *pest, char *src, int n);
char *get_path(char *cmd);
char *_getenv(char *name);
char **tokenenv(char *path);
extern char **environ;
void geterror(denum *n, char **abc, char *cmd);
#endif
