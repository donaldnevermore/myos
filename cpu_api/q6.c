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
        int rc_wait = waitpid(-1, NULL, WUNTRACED | WCONTINUED);
        printf("child wait: %d\n", rc_wait);
    }
    else {
        int wstatus;
        int rc_wait = waitpid(rc, &wstatus, WUNTRACED | WCONTINUED);
        printf("parent pid: %d\n", rc);
        printf("parent wait: %d\n", rc_wait);
        printf("if the child terminated normally: %s\n", WIFEXITED(wstatus) ? "true" : "false");
    }
}
