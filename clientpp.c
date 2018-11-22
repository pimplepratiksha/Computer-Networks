#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
int main()
{
	int sockfd,valread;
	struct sockaddr_in server_address;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr=INADDR_ANY;
	server_address.sin_port=htons(5333);
	//printf("htons - %d",htons(5333));
	//49152 - public port
	connect(sockfd,(struct sockaddr *)&server_address,sizeof(server_address));
	send(sockfd,"hello",strlen("hello"),0);
}
