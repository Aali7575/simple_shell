#include "shell.h"
/**
 * main - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */




int env_ndoro()
{
char command[MAX_COMMAND_LENGTH];
char *args[MAX_ARGS];
char *token;
ssize_t bytes_written;
ssize_t bytes_read;
int i;
pid_t pid;  
while (1)
{
const char prompt[] = "shell> ";
bytes_written = write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
if (bytes_written == -1)
{
perror("Write failed");
exit(1);
}
bytes_read = read(STDIN_FILENO, command, sizeof(command) - 1);
if (bytes_read == -1)
{
perror("Read failed");
exit(1);
}
if (command[bytes_read - 1] == '\n')
{
command[bytes_read - 1] = '\0';
}
token = strtok(command, " ");
i = 0;  
while (token != NULL)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;
if (strcmp(args[0], "env") == 0)
{
char **env = environ;
while (*env)
{
bytes_written = write(STDOUT_FILENO, *env, strlen(*env));
if (bytes_written == -1)
{
perror("Write failed");
exit(1);
}
bytes_written = write(STDOUT_FILENO, "\n", 1);
if (bytes_written == -1)
{
perror("Write failed");
exit(1);
}
env++;
}
continue;
}
pid = fork();
if (pid < 0)
{
perror("Fork failed");
exit(1);
}
else if (pid == 0)
{
execve(args[0], args, NULL);
perror("Unknown command");
exit(1);
}
else
{
wait(NULL);
}
}
return (0);
}
