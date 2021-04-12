#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

        char *myargs[0];
        myargs[0] = strdup("wc"); // word count
        myargs[1] = strdup("p4.c"); // file to count
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    }
    else {
        int rc_wait = wait(NULL);
    }
    return 0;
}
