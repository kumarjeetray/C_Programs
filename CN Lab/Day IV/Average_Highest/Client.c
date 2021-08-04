#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<sys/stat.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<arpa/inet.h>

int main()

{

struct sockaddr_in client,server;

int s,n,i;

int b1[5],b2[2];

s=socket(AF_INET,SOCK_DGRAM,0);

server.sin_family=AF_INET;

server.sin_port=2400;

server.sin_addr.s_addr=inet_addr("127.0.0.1");

printf("\nConnected with server\n");

n=sizeof(server);

printf("\nClient:\n");

for(i=0;i<5;i++)

{

printf("Enter a number:");

scanf("%d",&b1[i]);

}

sendto(s,b1,sizeof(b1),0,(struct sockaddr *) &server,n);

recvfrom(s,b2,sizeof(b2),0,NULL,NULL);

return 0;

}
