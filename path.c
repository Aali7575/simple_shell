#include "shell.h"

/**
 *main-entry point
 * command -Buffer to store the command line
 * args:array to store command
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int main(void)
{
char command[MAX_COMMAND_LENGTH];
char *args[MAX_ARGS];
char *token;
ssize_t bytes_written;

while (1)
{
const char prompt[] = "shell ";
bytes_written = write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
if (bytes_written == -1)
{
perror("Write failed");
exit(1);
}
ssize_t bytes_read = read(STDIN_FILENO, command, sizeof(command));
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
int i = 0;
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
pid_t pid = fork();
if (pid < 0)
{
perror("Fork failed");
exit(1);
}
else if (pid == 0)
{
execve(args[0], args, NULL);
perror("Wrong command");
exit(0);
}
else
{
wait(NULL);
}
}
return (0);
}
