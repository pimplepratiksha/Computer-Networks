#include<string.h>
#include<sys/ioctl.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<net/if_arp.h>
#include<unistd.h>
#define max 100
int main()
{
	int sd,b,cd;
	char fname[50],buff[100];
	struct sockaddr_in caddr,saddr;
	FILE *fp;
	
	socklen_t clen=sizeof(caddr);
	sd=socket(AF_INET,SOCK_STREAM,0);
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(3490);
	saddr.sin_addr.s_addr=htonl(INADDR_ANY);
	b=bind(sd,(struct sockaddr*)&saddr,sizeof(saddr));

	listen(sd,5);
	cd=accept(sd,(struct sockaddr*)&caddr,&clen);

	recv(cd,fname,sizeof(fname),0);
	fp=fopen(fname,"w+");

	
	while(recv(cd,buff,sizeof(buff),0))
	{
	  printf("\n%s",buff);
	  //fwrite(buff,sizeof(buff),1,fp);
	  fputs(buff,fp);
	  fflush(fp);
	  bzero(buff,sizeof(buff));
		
	}
	printf("\n\nThe file has been transferred\n");
	fclose(fp);
	close(cd);
	close(sd);
	
	return 0;
}
