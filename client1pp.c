#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>

int main()
{
	int sockfd,accepted_conn,valread;
	char buffer[1024];
	struct sockaddr_in server_address;
	int address_len=sizeof(server_address);
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(8080);	

	connect(sockfd,(struct sockaddr *)&server_address,sizeof(server_address));
	
	send(sockfd,"a.c",strlen("a.c"),0);
}
