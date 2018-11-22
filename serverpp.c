#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
	char buffer[1024];
	int sockfd,valread,accepted_conn;
	struct sockaddr_in server_address;
	int address_len=sizeof(server_address);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr=INADDR_ANY;
	server_address.sin_port=htons(5333);
	bind(sockfd,(struct sockaddr *)&server_address,sizeof(server_address));
	listen(sockfd,3);
	while(1)
	{
		accepted_conn=accept(sockfd,(struct sockaddr *)&server_address,(socklen_t*)&address_len);
		//printf("\n%d\n",accepted_conn);
		valread=read(accepted_conn,buffer,1024);
		printf("%s\n",buffer);
		close(accepted_conn);
	}
}
