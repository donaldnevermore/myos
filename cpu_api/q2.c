#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void run(void) {
    int fd = open("./q2_test.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();

    write(fd, "hello\n", strlen("hello\n"));

    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        write(fd, "child\n", strlen("child\n"));
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    }
    else {
        // Why is the print message incorrect? Uncomment to fix it.
        // int rc_wait = wait(NULL);
        write(fd, "parent\n", strlen("parent\n"));
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
    }

    close(fd);
}
