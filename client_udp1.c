/*senderprog.c - a client, datagram*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

/* the port users will be connecting to */

#define MYPORT 4950
int main(int argc, char *argv[ ])
{
int sockfd;

/* connector’s address information */
struct sockaddr_in dest_addr;

//it is a datatype to represent entry in host database
struct hostent *he;
int numbytes;
if (argc != 3)
{

fprintf(stderr, "Client-Usage: %s <hostname> <file>\n", argv[0]);

exit(1);

}

/* get the host info */

 
if ((he = gethostbyname(argv[1])) == NULL)

exit(1);



else

printf("ok...\n");

 

if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)

{

perror("Client-socket() error lol!");

exit(1);

}

else

printf("Client-socket() sockfd is OK...\n");

 

/* host byte order */

dest_addr.sin_family = AF_INET;

/* short, network byte order */

printf("Using port: 4950\n");

dest_addr.sin_port = htons(MYPORT);

dest_addr.sin_addr = *((struct in_addr *)he->h_addr);

/* zero the rest of the struct */

memset(&(dest_addr.sin_zero), '\0', 8);

 

if((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr))) == -1)


exit(1);

else
printf("sent %d bytes to %s\n", numbytes, inet_ntoa(dest_addr.sin_addr));

 

 if(close(sockfd))
printf("Client-sockfd successfully closed!\n");

return 0;

}
