#include<sys/types.h>//use for diff datatypes
#include<sys/socket.h>//internet protocol family
#include<netinet/in.h>//internet protocol family
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>

int main()
{
 
  int sockfd,accepted_conn,valread,address_len,num;
   char buffer[1024];
    socklen_t size;
   struct sockaddr_in server_address;
   address_len=sizeof(server_address);
   sockfd=socket(AF_INET,SOCK_STREAM,0);
   
   server_address.sin_family=AF_INET;
   server_address.sin_addr.s_addr=INADDR_ANY;
   server_address.sin_port=htons(3490);

   bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
   listen(sockfd,3);
 
   while(1) {

        size = sizeof(struct sockaddr_in);

        if ((accepted_conn = accept(sockfd, (struct sockaddr *)&server_address, &size))==-1 ) {
            perror("accept");
            exit(1);
        }
        printf("Server got connection from client \n");

        while(1) {

                if ((num = recv(accepted_conn, buffer, 1024,0))== -1) {
                        perror("recv");
                        exit(1);
                }
                else if (num == 0) {
                        printf("Connection closed\n");
                        //So I can now wait for another client
                        break;
                }
               
                buffer[num] = '\0';
               
                printf("Server:Msg Received %s\n", buffer);
                if ((send(accepted_conn,buffer, strlen(buffer),0))== -1) 
                {
                     fprintf(stderr, "Failure Sending Message\n");
                     close(accepted_conn);
                     break;
                                         
                }

               
        } close(accepted_conn);
    }    close(sockfd);
    return 0;
} 




