#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void run(void) {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int rc[2];
    rc[0] = fork();

    if (rc[0] < 0) {
        fprintf(stderr, "fork failed.\n");
        exit(EXIT_FAILURE);
    }
    else if (rc[0] == 0) {
        close(pipefd[0]);

        if (dup2(pipefd[1], STDOUT_FILENO) != STDOUT_FILENO) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        close(pipefd[1]);

        printf("First child says hello.");
    }
    else {
        rc[1] = fork();
        if (rc[1] < 0) {
            fprintf(stderr, "fork failed.\n");
            exit(EXIT_FAILURE);
        }
        else if (rc[1] == 0) {
            close(pipefd[1]);
            if (dup2(pipefd[0], STDIN_FILENO) != STDIN_FILENO) {
                perror("pipe");
                exit(EXIT_FAILURE);
            }
            close(pipefd[0]);

            char buf[BUFSIZ];
            read(STDIN_FILENO, buf, BUFSIZ);
            printf("Second child prints: %s\n", buf);
        }
        else {
            waitpid(rc[0], NULL, 0);
            waitpid(rc[1], NULL, 0);
        }
    }
}
