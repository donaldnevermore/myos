#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void sigcont_handler() {
    printf("goodbye\n");
}

void run(void) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        fprintf(stderr, "pipe failed\n");
        exit(EXIT_FAILURE);
    }

    pid_t rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        printf("hello\n");
        close(pipefd[0]);
        write(pipefd[1], "c", 1);
        close(pipefd[1]);
    } else {
        close(pipefd[1]);
        char c;
        read(pipefd[0], &c, 1); // block
        close(pipefd[0]);
        printf("goodbye\n");
    }
}

void runSignal(void) {
    struct sigaction act;
    act.sa_handler = sigcont_handler;

    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello\n");
        kill(getppid(), SIGCONT);
    } else {
        sigaction(SIGCONT, &act, NULL);
        pause();
    }
}
