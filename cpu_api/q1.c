#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void run(void) {
    int x = 100;
    int rc = fork();

    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 66;
        printf("child pid: %d, x: %d\n", (int)getpid(), x);
    } else {
        x = 88;
        printf("parent pid: %d, x: %d\n", (int)getpid(), x);
        wait(NULL);
    }
    printf("%p\n", &x);
}
