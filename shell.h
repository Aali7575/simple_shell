#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
int path_main(void);
int exit_main(void);
int shell_main(void);
int env_main(void);
#endif

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10
#define MAX_PATH_LENGTH 1024
#define STDOUT_FD 1
extern char **environ;
