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
        pid_t rc_wait = waitpid(-1, NULL, WUNTRACED | WCONTINUED);
        printf("child wait: %d\n", rc_wait);
    } else {
        int wstatus;
        pid_t rc_wait = waitpid(rc, &wstatus, WUNTRACED | WCONTINUED);
        printf("parent pid: %d\n", rc);
        printf("parent wait: %d\n", rc_wait);
        printf("if the child terminated normally: %s\n", WIFEXITED(wstatus) ? "true" : "false");
    }
}
