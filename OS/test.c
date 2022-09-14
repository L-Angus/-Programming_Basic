#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int x = 100;
    printf("main process(pid: %d) x : %d\n", getpid(), x);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (rc == 0) {
        // x = x + 1;
        printf("child process(pid: %d) x : %d\n", getpid(), x);
    }
    else {
        // x = x + 1;
        // int wc = wait(NULL);
        x = 0;
        printf("parent process(pid: %d) x : %d\n", getpid(), x);
    }

    return 0;
}