#include<string.h>
#include<sys/ioctl.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<net/if_arp.h>
#include<unistd.h>
int main()
{
	int sd,b,cd,num;
	char fname[50],buff[1000];
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

	while(1)
	{
	        
		if((num=recv(cd,buff,sizeof(buff),0))==-1)
		{
			perror("recv");
			exit(1);
		}
		else if (num == 0) 
		{
			printf("Connection closed\n");
			
			break;
		}
		buff[num]='\0';
		printf("\n%s.%d.",buff,num);
		fwrite(buff,strlen(buff),1,fp);
	}
			printf("\n%s.%d.",buff,num);
	printf("the file has been transferred");
	fclose(fp);
	close(cd);
	close(sd);

	return 0;
}
