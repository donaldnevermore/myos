#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void run(void) {
    pid_t rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed.\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("child\n");
    } else {
        wait(NULL);
        printf("parent\n");
    }
}
