#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char *command = NULL;
    size_t command_size = 0;
    ssize_t characters_read;

    printf("$ ");
    fflush(stdout);  // Flush the output to ensure the prompt is printed

    characters_read = getline(&command, &command_size, stdin);

    if (characters_read == -1) {
        printf("Error reading the command\n");
        free(command);
        return 1;
    }

    printf("titoand ndoro simple shell: %s", command);

    free(command);
    return 0;
}
