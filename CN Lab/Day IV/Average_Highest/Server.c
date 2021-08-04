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

int b1[5],b2[2];

s=socket(AF_INET,SOCK_DGRAM,0);

server.sin_family=AF_INET;

server.sin_port=2400;

server.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(s,(struct sockaddr *)&server,sizeof(server));

printf("\nWaiting for client\n");

n=sizeof(client);

recvfrom(s,b1,sizeof(b1),0,(struct sockaddr *) &client,&n);

int sum = 0;

for(i=0;i<5;i++)

{

for(j=i+1;j<5;j++)

{

if(b1[i] > b1[j])

{

int temp = b1[i];

b1[i] = b1[j];

b1[j] = temp;

}

}

sum = sum + b1[i];

}

b2[0] = sum;

b2[1] = b1[4];

printf("Total Sum:%d\n",b2[0]);

printf("Highest:%d",b2[1]);

sendto(s,b2,sizeof(b2),0,(struct sockaddr *) &client,n);

return 0;

}
