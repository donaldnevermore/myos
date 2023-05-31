#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void run(void) {
    pid_t rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        pid_t rc_wait = wait(NULL);
        printf("child wait: %d\n", rc_wait);
    } else {
        pid_t rc_wait = wait(NULL);
        printf("parent wait: %d\n", rc_wait);
    }
}
