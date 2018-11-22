#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
 
  int sockfd,accepted_conn,valread,address_len;
   char buffer[1024];
   struct sockaddr_in server_address;
   address_len=sizeof(server_address);
   sockfd=socket(AF_INET,SOCK_STREAM,0);
   
   server_address.sin_family=AF_INET;
   server_address.sin_addr.s_addr=INADDR_ANY;
   server_address.sin_port=htons( 5000);

   bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
   listen(sockfd,3);
 
  
       //accepted_conn=accept(sockfd, (struct sockaddr *)&server_address, (socklen_t*)&address_len);

 	while(1)
 	{
 		size=sizeof(struct sockaddr_in);
 		if((client_fd =accept(sockfd,(struct sockaddr *)&destzzzzzzz   
}



