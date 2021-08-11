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

int arr[5],largest[1];

s=socket(AF_INET,SOCK_DGRAM,0);

server.sin_family=AF_INET;

server.sin_port=2900;

server.sin_addr.s_addr=inet_addr("127.0.0.1");

printf("\nConnected with server\n");

n=sizeof(server);

printf("\nClient:\n");

for(i=0;i<5;i++)

{

printf("Enter a number:");

scanf("%d",&arr[i]);

}

sendto(s,arr,sizeof(arr),0,(struct sockaddr *) &server,n);

recvfrom(s,largest,sizeof(largest),0,NULL,NULL);

printf("Largest Number:%d",largest[0]);

return 0;

}
