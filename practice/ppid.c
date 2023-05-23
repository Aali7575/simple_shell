#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t parentPID = getppid();
    printf("Parent PID: %d\n", parentPID);

    return 0;
}
