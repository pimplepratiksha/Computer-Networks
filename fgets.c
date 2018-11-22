#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
  int fp,fp1;
  char buffer[2];
  int n=sizeof(buffer);
  fp=open("try.txt",O_RDONLY,0640);
  fp1=open("try1.txt",O_CREAT| O_WRONLY,0640);
  while(read(fp,buffer,sizeof(buffer)))
  {
    write(fp1,buffer,strlen(buffer));
    bzero(buffer,sizeof(buffer));
  }
  close(fp);
  close(fp1);
  return 0;
}
