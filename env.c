#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

extern char **environ;

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    char *token;
    ssize_t bytes_written;

    while (1) {
        // Write shell prompt
        const char prompt[] = "shell> ";
        bytes_written = write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
        if (bytes_written == -1) {
            perror("Write failed");
            exit(1);
        }

        // Read the command line
        ssize_t bytes_read = read(STDIN_FILENO, command, sizeof(command));
        if (bytes_read == -1) {
            perror("Read failed");
            exit(1);
        }

        // Remove trailing newline character
        if (command[bytes_read - 1] == '\n') {
            command[bytes_read - 1] = '\0';
        }

        // Tokenize the command line
        token = strtok(command, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Check if it's the 'env' command
        if (strcmp(args[0], "env") == 0) {
            char **env = environ;
            while (*env) {
                bytes_written = write(STDOUT_FILENO, *env, strlen(*env));
                if (bytes_written == -1) {
                    perror("Write failed");
                    exit(1);
                }
                bytes_written = write(STDOUT_FILENO, "\n", 1);
                if (bytes_written == -1) {
                    perror("Write failed");
                    exit(1);
                }
                env++;
            }
            continue;
        }

        // Fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            execve(args[0], args, NULL);
            perror("Unknown command");
            exit(0);
        } else {
            // Parent process
            wait(NULL);
        }
    }

    return 0;
}
