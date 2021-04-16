#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void run(void) {
    int fd = open("./q2_test.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();

    // Why did it cause incorrect print message?
    write(fd, "hello\n", 6);

    if (rc == 0) {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    }
    else {
        // Uncomment to fix it.
        // int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
    }
}
