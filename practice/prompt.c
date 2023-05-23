#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 10

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;  // Invalid arguments
    }

    if (*lineptr == NULL) {
        *n = INITIAL_BUFFER_SIZE;
        *lineptr = malloc(*n);
        if (*lineptr == NULL) {
            return -1;  // Memory allocation error
        }
    }

    int c;
    size_t pos = 0;

    while ((c = fgetc(stream)) != EOF) {
        if (pos + 1 >= *n) {  // Increase buffer size if necessary
            size_t new_size = *n * 2;
            char *new_ptr = realloc(*lineptr, new_size);
            if (new_ptr == NULL) {
                return -1;  // Memory allocation error
            }
            *lineptr = new_ptr;
            *n = new_size;
        }

        (*lineptr)[pos++] = (char)c;

        if (c == '\n') {
            break;  // End of line
        }
    }

    (*lineptr)[pos] = '\0';  // Null-terminate the string

    if (pos == 0 && c == EOF) {
        return -1;  // No characters read (end-of-file)
    }

    return pos;  // Return the number of characters read
}

int main() {
    char *line = NULL;
    size_t line_size = 0;
    ssize_t characters_read;

    printf("$ ");
    fflush(stdout);

    characters_read = custom_getline(&line, &line_size, stdin);

    if (characters_read == -1) {
        printf("Error reading the command\n");
        free(line);
        return 1;
    }

    printf("You entered: %s", line);

    free(line);
    return 0;
}
