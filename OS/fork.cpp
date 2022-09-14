#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
// #include <iostream>


int main(int argc, char* argv[]) {
    printf("hello world(pid: %d)\n", getpid());
    int rc = fork();
    if (rc < 0) {
        // std::cout << "fork failed!" << std::endl;
        // return -1;
        fprintf(stderr, "fork failed!");
        exit(1);
    }
    else if (rc == 0) {
        printf("hello, i am child(pid: %d)\n", getpid());
        char* myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("fork.cpp");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this shouldn't print out");
    }
    else {
        int wc = wait(NULL);
        printf("hello, i am parent of %d (wc: %d) (pid: %d)\n", rc, wc, getppid());
    }
    return 0;
}