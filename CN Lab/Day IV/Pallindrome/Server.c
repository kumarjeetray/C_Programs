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

server.sin_port=2100;

server.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(s,(struct sockaddr *)&server,sizeof(server));

printf("\nWaiting for client\n");

n=sizeof(client);

recvfrom(s,b1,sizeof(b1),0,(struct sockaddr *) &client,&n);

printf("\nClient:%s",b1);

if(b1[0] == b1[2])

{

strcpy(b1,"It is a pallindrome number");

}

else

{

strcpy(b1,"It is a not a pallindrome number");

}

printf("\nServer:%s",b1);

sendto(s,b1,sizeof(b1),0,(struct sockaddr *) &client,n);

return 0;

}
