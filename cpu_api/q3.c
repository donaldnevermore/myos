#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void sigcont_handler() { printf("goodbye\n"); }

void run() {
    int parent_id = getpid();
    int rc = fork();

    struct sigaction act;
    act.sa_handler = sigcont_handler;

    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("hello\n");
        kill(parent_id, SIGCONT);
    }
    else {
        sigaction(SIGCONT, &act, NULL);
        pause();
    }
}
