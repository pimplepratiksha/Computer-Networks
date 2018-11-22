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
 FILE *fp1; 
 char filename[1024];
  char s[100];
  int address_len=sizeof(server_address);
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  server_address.sin_family=AF_INET;
  server_address.sin_addr.s_addr=inet_addr("192.168.1.1");
  server_address.sin_port=htons(5000);
  connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
  printf("%d",sockfd);
 // while(1)
 	//printf("\nEnter file name:");
	//scanf("%s",filename);
	fp1=fopen("study1.txt","r");
	
	
	if(fscanf(fp1,"%s",s)!=EOF)
	{
		printf("\n%s",s);
		if(send(sockfd,s, strlen(s),0)<0)
			{
			perror("send");
			exit(EXIT_FAILURE);
			}
		/*if ((send(sockfd,s, strlen(s),0))== -1)
		 {
                fprintf(stderr, "Failure Sending Message\n");
                close(sockfd);
                exit(1);
        	}*/
        }
       

        
	fclose(fp1);


    close(sockfd);   
}



