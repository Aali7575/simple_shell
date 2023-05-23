#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *p;
    char path[100];
    int max_pid;

    // Open the pid_max file for reading
    p = fopen("/proc/sys/kernel/pid_max", "r");
    if (p == NULL) {
        printf("Failed to open pid_max file\n");
        return 1;
    }

    // Read the maximum PID value
    fgets(path, sizeof(path), p);
    max_pid = atoi(path);

    // Close the file
    fclose(p);

    // Print the maximum PID value
    printf("Maximum Process ID: %d\n", max_pid);

    return 0;
}
