#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include<fcntl.h>
#include<stdbool.h>
#define MYPORT 4950

int main(int argc, char *argv[ ])
{
  int sockfd,addr_len;
  char *buff,fname[10];
  char ack[3]="0";
	buff=(char *)malloc(sizeof(char)*10);
	int fp;
	
	struct sockaddr_in dest_addr;
	struct hostent *he;
	int numbytes;
	
	addr_len=sizeof(struct sockaddr);
	if (argc != 3)
	{
	  printf("Filename is not given");
		exit(1);
	}
	
	if ((he = gethostbyname(argv[1])) == NULL)
		exit(1);
	
	strcpy(fname,argv[2]);
	
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
	  exit(1);
	}
	
       
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(MYPORT);
	dest_addr.sin_addr = *((struct in_addr *)he->h_addr);
	memset(&(dest_addr.sin_zero), '\0', 8);

	if((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr))) == -1)
	  {
	    printf("\nIp address not found !!!");
	    close(fp);
	    if(close(sockfd)>-1)
		printf("\nFile tranfer fails!\n");
	    return -1;
	  }
	else
	  {
	        printf("%s tranfer starts...",fname);
		fp=open(fname,O_RDONLY,0600);
	        if (fp!=-1)
		  {
		    while(read(fp,buff,sizeof(buff)))
		      {
			
			printf("\n%s",buff);
			sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
			bzero(buff,strlen(buff));
	
		      }
		  }
		else
		  {
		    printf("\n File not exixts !!!\n");
		    exit(0);
		  }
	   }
	
	 
	  
	close(fp);
	if(close(sockfd)>-1)
		printf("File send successfully!\n");

	return 0;

}
