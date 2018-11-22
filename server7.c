#include<string.h>
#include<sys/ioctl.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<net/if_arp.h>
#include<unistd.h>
#include<fcntl.h>
#define max 100
int main()
{
	int sd,b,cd;
	char fname[50], *buff;
	buff=(char *)malloc(sizeof(char)*10);
	struct sockaddr_in caddr,saddr;
	int fp;
	socklen_t clen=sizeof(caddr);
	sd=socket(AF_INET,SOCK_STREAM,0);
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(3490);
	saddr.sin_addr.s_addr=htonl(INADDR_ANY);
	b=bind(sd,(struct sockaddr*)&saddr,sizeof(saddr));

	listen(sd,5);
	cd=accept(sd,(struct sockaddr*)&caddr,&clen);

	recv(cd,fname,sizeof(fname),0);
	fp=open(fname,O_WRONLY|O_CREAT,0);

	while(recv(cd,buff,sizeof(buff),0))
	  {
	    write(fp,buff,strlen(buff));
	    bzero(buff,sizeof(buff));
	  }
	

	printf("\n\nThe file has been transferred\n");
	close(fp);
	close(cd);
	close(sd);
	
	return 0;
}
