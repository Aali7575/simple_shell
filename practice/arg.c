#include <stdio.h>

int main(int argc, char* argv[]) {
    char** current_arg = argv + 1;  // Start at the second element

    while (*current_arg != NULL) {
        printf("%s\n", *current_arg);
        current_arg++;
    }

    return 0;
}
