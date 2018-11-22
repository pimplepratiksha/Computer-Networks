/*receiverprog.c - a server, datagram sockets*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define sourcePORT 4950
#define MAXBUFLEN 500

int main(int argc, char *argv[])
{
int sockfd;
/* source address information */
struct sockaddr_in source_addr;
/* connector’s address information */
struct sockaddr_in their_addr;
int addr_len, numbytes;
char buf[MAXBUFLEN];

if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    exit(1);

/* host byte order */
source_addr.sin_family = AF_INET;
/* short, network byte order */
source_addr.sin_port = htons(sourcePORT);
/* automatically fill with source IP */
source_addr.sin_addr.s_addr = INADDR_ANY;
/* zero the rest of the struct */
memset(&(source_addr.sin_zero), '\0', 8);

if(bind(sockfd, (struct sockaddr *)&source_addr, sizeof(struct sockaddr)) == -1)
    exit(1);
addr_len = sizeof(struct sockaddr);

if((numbytes = recvfrom(sockfd, buf, MAXBUFLEN-1, 0, (struct sockaddr *)&their_addr, &addr_len)) == -1)
{
	perror("error while receiving message...");    
        exit(1);
}

else
    printf("message received successfully....\n");

printf("Server-Got packet from %s\n", inet_ntoa(their_addr.sin_addr));
printf("Server-Packet is %d bytes long\n", numbytes);
buf[numbytes] = '\0';
printf("Server-Packet contains \"%s\"\n", buf);

if(close(sockfd) != 0)
    printf("socket closing failed!\n");
return 0;

}
