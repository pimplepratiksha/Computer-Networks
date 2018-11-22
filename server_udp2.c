#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<fcntl.h>

#define sourcePORT 4950
#define MAXBUFLEN 50

int main(int argc, char *argv[])
{
	int sockfd,fp;
	struct sockaddr_in source_addr;
	struct sockaddr_in their_addr;
	int addr_len, numbytes;
	char *buf,*fname,ack[2]="0",end[]="EOF";
	fname=(char *)malloc(sizeof(char)*20);
	buf=(char *)malloc(sizeof(char)*10);

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
		exit(1);

	source_addr.sin_family = AF_INET;
	source_addr.sin_port = htons(sourcePORT);
	source_addr.sin_addr.s_addr = INADDR_ANY;
	memset(&(source_addr.sin_zero), '\0', 8);

	if(bind(sockfd, (struct sockaddr *)&source_addr, sizeof(struct sockaddr)) == -1)
		exit(1);
	addr_len = sizeof(struct sockaddr);

	if((numbytes = recvfrom(sockfd, fname, MAXBUFLEN-1, 0, (struct sockaddr *)&their_addr, &addr_len)) == -1)
	{
		perror("error while receiving message...");    
		exit(1);
	}
	else
	{
		printf("message received successfully....\n");
		//strcpy(ack,"1");
		//sendto(sockfd,ack,strlen(ack),0,(struct sockaddr *)&their_addr,sizeof(struct sockaddr));
	}
	

	bzero(buf,sizeof(fname));

	printf("message contains \"%s\"\n\n\n", fname);
	
	fp=open(fname,O_WRONLY|O_CREAT,0600);

	while(numbytes=recvfrom(sockfd, buf, MAXBUFLEN-1, 0, (struct sockaddr *)&their_addr, &addr_len)!=' ')
       	{
	  //printf("\n%d",numbytes);
	  printf("%s",buf);	
		write(fp,buf,strlen(buf));
		bzero(buf,sizeof(buf));
		if(strcmp(buf,end)==0)
		{
		  printf("\n\nThe file has been transferred\n");
		  close(fp);
		  close(sockfd);
		}
	}
        
	if(close(fp));
	     printf("file not received...!\n");
	if(close(sockfd) != 0)
	    printf("socket closing failed!\n");
 
	return 0;

}
