#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
  int x = 100;
  int rc = fork();
  
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello, i am child (pid:%d) and my initial x value is %d\n", (int) getpid(), x);
    x = 99;
    printf("hello, i am child (pid:%d) and my x value is %d\n", (int) getpid(), x);
  } else{
    printf("hello, i am parent (pid:%d) and my initial x value is %d\n", (int) getpid(), x);
    x = 88;
    printf("hello, i am parent (pid:%d) and my x value is %d\n", (int) getpid(), x);
  }

  printf("i am (pid:%d) and my x value is %d\n", (int) getpid(), x);
  return 0;


}
