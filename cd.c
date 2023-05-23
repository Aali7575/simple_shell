#include "shell.h"

/**
 * change_directory-used in swithing dir
 * @crent_dir: current directory
 *path-used in locating path
 * Return: 1 if interactive mode, 0 otherwise
 */
void change_directory(const char *path) {  
char crent_dir[MAX_PATH_LENGTH];
char new_dir[MAX_PATH_LENGTH];
if (getcwd(crent_dir,
sizeof(crent_dir)) == NULL)
{
perror("getcwd error");
return;
}
if (strcmp(path, "-") == 0)
{
const char *pre_dir = getenv("pwd");
if (pre_dir == NULL)
{
write(STDERR_FILENO,
"cd: pwd not set\n", strlen("cd: pwd not set\n"));
return;
}
path = pre_dir;
write(STDOUT_FILENO, path, strlen(path));
write(STDOUT_FILENO, "\n", 1);
}
if (chdir(path) != 0)
{
perror("chdir error");
return;
}
if (setenv("pwd", crent_dir, 1) != 0)
{
perror("setenv error");
return;
}
if (getcwd(new_dir, sizeof(new_dir)) == NULL)
{
perror("getcwd error");
return;
}
if (setenv("PWD", new_dir, 1) != 0)
{
perror("setenv error");
return;
}
}
int main(int argc, char *argv[])
{
if (argc == 1)
{
const char *home_dir = getenv("HOME");
if (home_dir == NULL)
{
write(STDERR_FILENO,
"cd: HOME not set\n", strlen("cd: HOME not set\n"));
return (1);
}
change_directory(home_dir);
}
else if (argc == 2)
{
change_directory(argv[1]);
}
else
{
write(STDERR_FILENO,
"cd: too many arguments\n", strlen("cd: too many arguments\n"));
return (1);
}
return (0);
}
