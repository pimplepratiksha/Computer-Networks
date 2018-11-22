#include<netinet/in.h>//internet address family
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>

#define MAXSIZE 1024
int main()
{
  int sockfd,accepted_conn,valread,num;
  struct sockaddr_in server_address;
  char buffer[1024];
  char buff[1024];
  int address_len=sizeof(server_address);
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  server_address.sin_family=AF_INET;
  server_address.sin_addr.s_addr=inet_addr("192.168.1.1");
  server_address.sin_port=htons(3490);
  connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));

  while(1) {
        printf("Client: Enter Data for Server:");
        fgets(buffer,MAXSIZE-1,stdin);
        if ((send(sockfd,buffer, strlen(buffer),0))== -1) {
                fprintf(stderr, "Failure Sending Message\n");
                close(sockfd);
                exit(1);
        }
        else {
                printf("Client:Message being sent: %s\n",buffer);
                num = recv(sockfd, buffer, sizeof(buffer),0);
                if ( num <= 0 )
                {
                        printf("Either Connection Closed or Error\n");
                        //Break from the While
                        break;
                }

                buff[num] = '\0';
                printf("Client:Message Received From Server -  %s\n",buffer);
           }
    }

    close(sockfd);   
}



