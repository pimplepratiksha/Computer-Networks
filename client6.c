#include<string.h>
#include<sys/ioctl.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<net/if_arp.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>

int main()
{
	int sockfd,c;
	char fname[50],sip[25],buff[200];
	struct sockaddr_in caddr;

	FILE *fp;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	caddr.sin_family=AF_INET;
	caddr.sin_port=htons(3490);
	caddr.sin_addr.s_addr=inet_addr("192.168.1.1");

	c=connect(sockfd,(struct sockaddr*)&caddr,sizeof(caddr));
	if(c==0)
		printf("\nconnected to server");
	printf("\nenter the file name - ");
	scanf("%s",fname);
	send(sockfd,fname,sizeof(fname),0);
	fp=fopen(fname,"r");
	while(fgets(buff,100,fp)!=NULL)
	{
		send(sockfd,buff,sizeof(buff),0);
		///printf("\n%s",buff);
	}
	fclose(fp);
	close(sockfd);

	return 0;
}
