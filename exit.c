#include "shell.h"

/**
 * main - changes the current directory of the process
 * command-Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

void exit_shell(void)
{
exit(EXIT_SUCCESS);
}
int exit_otis(void)
{
char command[MAX_COMMAND_LENGTH];
ssize_t bytes_written;
while (1)
{
bytes_written = write(STDOUT_FD,
"Shell $: ", sizeof("Shell $: ") - 1);
if (bytes_written == -1)
{
perror("write error");
exit(EXIT_FAILURE);
}
bytes_written = read(STDIN_FILENO, command, sizeof(command));
if (bytes_written == -1)
{
perror("read error");
exit(EXIT_FAILURE);
}
command[strcspn(command, "\n")] = '\0';
if (strcmp(command, "exit") == 0)
{
exit_shell();
}
else
{
}
}
return (0);
}
