#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main() {
  system("gcc client.c -o client");
  system("gcc server.c -o server");

  int pid = fork();
  if (pid == 0) {
    char* argv[] = {"./client",NULL,NULL,NULL};
    execv("./client",argv);
    exit(0);
  }

  else {
    char* argv[] = {"./server ",NULL,NULL,NULL};
    execv("./server",argv);
    exit(0);
  }
}

