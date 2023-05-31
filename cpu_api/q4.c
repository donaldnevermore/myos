#define _GNU_SOURCE
#if __has_include(<features.h>)
#include <features.h> // __GNU_LIBRARY__
#endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void run(void) {
    pid_t rc = fork();

    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        char *argv[] = {"ls", "-l", "-a", "-h", NULL};
        char *envp[] = {"PATH=/bin:/usr/bin", NULL};

        // execl("/bin/ls", "ls", "-l", "-a", "-h", NULL);
        // execle("/bin/ls", "ls", "-l", "-a", "-h", NULL, envp);
        // execlp("ls", "ls", "-l", "-a", "-h", NULL);
        // execv("/bin/ls", argv);
        // execvp("ls", argv);

        // execve("/bin/ls", argv, envp);
        execvpe("ls", argv, envp);
    } else {
        int rc_wait = wait(NULL);
    }
}
