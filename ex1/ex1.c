// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    printf("Parent\n");
    int x = 100;
    int rc = fork();
    if (rc < 0) {
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc == 0) {
      x = 101;
      printf("Student: x is %d\n", x);
    } else {
      printf("Parent: %d, of student: %d\n", (int) getpid(), rc);
      x = 1000;
    }
    printf("x is %d\n", x);
    return 0;
}
