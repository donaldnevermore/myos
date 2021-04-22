#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void run(void) {
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        int rc_wait = wait(NULL);
        printf("child wait: %d\n", rc_wait);
    }
    else {
        int rc_wait = wait(NULL);
        printf("parent wait: %d\n", rc_wait);
    }
}
