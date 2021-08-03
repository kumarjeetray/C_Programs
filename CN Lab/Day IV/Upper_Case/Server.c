#include<stdio.h>

#include<string.h>

#include<sys/stat.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<arpa/inet.h>

int main()

{

struct sockaddr_in client,server;

int s,n,i;

char b1[100],b2[100];

s=socket(AF_INET,SOCK_DGRAM,0);

server.sin_family=AF_INET;

server.sin_port=2000;

server.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(s,(struct sockaddr *)&server,sizeof(server));

printf("\nWaiting for client\n");

n=sizeof(client);

recvfrom(s,b1,sizeof(b1),0,(struct sockaddr *) &client,&n);

printf("\nClient:%s",b1);
  
for (i = 0; b1[i]!='\0'; i++) {

if(b1[i] >= 'a' && b1[i] <= 'z') {

b1[i] = b1[i] - 32;

}

}
printf("\nServer:%s",b1);
sendto(s,b1,sizeof(b1),0,(struct sockaddr *) &client,n);

return 0;

}
