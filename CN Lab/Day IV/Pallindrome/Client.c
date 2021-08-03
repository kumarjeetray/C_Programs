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

int s,n;

char b1[100],b2[100];

s=socket(AF_INET,SOCK_DGRAM,0);

server.sin_family=AF_INET;

server.sin_port=2100;

server.sin_addr.s_addr=inet_addr("127.0.0.1");

printf("\nConnected with server\n");

n=sizeof(server);

printf("\nClient - Enter a three digit number:");

gets(b2);

sendto(s,b2,sizeof(b2),0,(struct sockaddr *) &server,n);

recvfrom(s,b1,sizeof(b1),0,NULL,NULL);

printf("\nServer:%s",b1);

return 0;

}



