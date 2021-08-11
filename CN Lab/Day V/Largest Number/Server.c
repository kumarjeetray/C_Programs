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

int s,n,i,j;

int arr[5],largest[1];

s=socket(AF_INET,SOCK_DGRAM,0);

server.sin_family=AF_INET;

server.sin_port=2900;

server.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(s,(struct sockaddr *)&server,sizeof(server));

printf("\nWaiting for client\n");

n=sizeof(client);

recvfrom(s,arr,sizeof(arr),0,(struct sockaddr *) &client,&n);

for(i=0;i<5;i++)

{

for(j=i+1;j<5;j++)

{

if(arr[i] > arr[j])

{

int temp = arr[i];

arr[i] = arr[j];

arr[j] = temp;

}

}

}

largest[0] = arr[4];

sendto(s,largest,sizeof(largest),0,(struct sockaddr *) &client,n);

return 0;

}
