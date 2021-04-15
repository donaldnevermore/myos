#include <stdio.h>
#include <unistd.h>

int x;

void run(void) {
    x = 100;
    int rc = fork();

    if (rc == 0) {
        x = 88;
        printf("child pid: %d, x: %d\n", (int)getpid(), x);
    }
    else {
        printf("parent pid: %d, x: %d\n", (int)getpid(), x);
    }
}
