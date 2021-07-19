/*
Write a C program to extract each byte from a given number and store them inseparate character variables and print the content of those variables
*/

#include<stdio.h>
int main()
{
	int num = 0x11223344;
	char a=(num&0xFF); 
    char b=((num>>8)&0xFF); 
    char c=((num>>16)&0xFF); 
    char d=((num>>24)&0xFF);
	printf("a= %02X\n",a);
    printf("b= %02X\n",b);
    printf("c= %02X\n",c);
    printf("d= %02X\n",d);
	return 0;
}
