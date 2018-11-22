#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>//file operations
#include<string.h>
#include<arpa/inet.h>//defination of internet operation
#include<net/if_arp.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<fcntl.h>//file modes of system call

int main(int argc,char *argv[])
{
	char fname[50],ip[25],*buff,end[5]="EOF";
	int sockfd,c;
	struct sockaddr_in caddr;
	printf("Entr ip -");
	scanf("%s",ip);
	while(strcmp(ip,"0")!=0)
	{

		buff=(char *)malloc(sizeof(char)*10);
		int fp;
		sockfd=socket(AF_INET,SOCK_STREAM,0);
		caddr.sin_family=AF_INET;
		caddr.sin_port=htons(3490);
		caddr.sin_addr.s_addr=inet_addr(ip);

		c=connect(sockfd,(struct sockaddr*)&caddr,sizeof(caddr));
		/*if(c==-1)
		{
			printf("\n Machine is not in ad-hoc");
			exit(1);	
		}*/
		if(c==0)
			printf("\nconnected to server");
		printf("\nenter the file name - ");
		scanf("%s",fname);
		send(sockfd,fname,sizeof(fname),0);
		fp=open(fname,O_RDONLY,0600);

		while(read(fp,buff,sizeof(buff)))
		{
			printf("%s",buff);
			send(sockfd,buff,strlen(buff),0);
			bzero(buff,sizeof(buff));
		}
		//printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&");
		send(sockfd,end,strlen(end),0);
			//printf("\njammooo\n%s",end);
			
		
		//printf("%s",buff);
		
		close(fp);
		printf("Entr ip -");
		scanf("%s",ip);
	}
	close(sockfd);
	return 0;
}
