#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define _GNU_SOURCE

void run(void) {
    int rc = fork();

    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        char *argvs[] = {"ls", "-l", "-a", "-h", NULL};
        char *envp[] = {NULL};

        // execl("/bin/ls", "ls", "-l", "-a", "-h", NULL);
        // execle("/bin/ls", "ls", "-l", "-a", "-h", NULL, envp);
        // execlp("ls", "ls", "-l", "-a", "-h", NULL);
        // execv("/bin/ls", argvs);
        // execvp("ls", argvs);
        execvpe("ls", argvs, envp);
    }
    else {
        int rc_wait = wait(NULL);
    }
}
