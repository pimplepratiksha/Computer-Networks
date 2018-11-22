#include <stdio.h> 
#include<string.h>
#include<stdlib.h>
int main() 
{
	char a[10],ip[20];
       int i;
	for(i=0;i<255;i++)
	{
		sprintf(a,"%d",i);
		strcat(ip,"192.168.1.");
		strcat(ip,a);
		printf("\n%s",ip);
		bzero(ip,sizeof(ip));
	}
} 
