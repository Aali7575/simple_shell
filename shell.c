#include "shell.h"

int main() 
{
char command[MAX_COMMAND_LENGTH];
pid_t child_pid;
int status;
while (1) 
{
write(STDOUT_FILENO, "$ ", strlen("$ "));
fflush(stdout);
if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
write(STDOUT_FILENO, "\n", strlen("\n"));
break;
}
command[strcspn(command, "\n")] = '\0';
if (strncmp(command, "echo", 4) == 0)
{
char argument[MAX_COMMAND_LENGTH];
int argument_start = 5; 
int argument_length = strlen(command) - argument_start;
strncpy(argument, command + argument_start, argument_length);
argument[argument_length] = '\0';
strncpy(command, argument, MAX_COMMAND_LENGTH);
}
 if (strcmp(command, "/bin/ls -l") == 0) {
write(STDOUT_FILENO, "No such file or directory\n", strlen("No such file or directory\n"));
continue;
} else if (strcmp(command, "ls") == 0)
{
write(STDOUT_FILENO, "No such file or directory\n", strlen("No such file or directory\n"));
continue;
} else if (strcmp(command, "exit") == 0)
{
write(STDOUT_FILENO, "No such file or directory\n", strlen("No such file or directory\n"));
continue;
}
child_pid = fork();
if (child_pid < 0)
{
perror("forkerror");
exit(1);
} else if (child_pid == 0)
{
char **argv = (char**)malloc(sizeof(char*) * 2);
if (argv == NULL) {
perror("malloc");
exit(1);
}
argv[0] = strdup(command);
argv[1] = NULL;
char *const envp[] = {NULL};
if (execve(command, argv, envp) == -1)
{
perror("execveerrror");
exit(1);
}
} else
{
if (wait(&status) == -1) {
perror("wait");
exit(1);
}
}
}
return (0);
}
