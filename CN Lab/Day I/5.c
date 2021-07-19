/*
Write a C program to check whether the Host machine is in Little Endian orBig Endian. 
Enter  a number, print the content of each byte location andConvert the Endianness of the same i.e. Little to Big Endian and vice-versa.
*/
#include <stdio.h>
int main(void)
{
    unsigned int value = 0x1;
    char *r = (char *) &value;
 
    if (*r == 1) 
        printf("System is Little Endian\n");
    else
        printf("System is Big Endian\n");
        
    printf("Value Before Converting = 0x%x\n", value);
    int leftmost_byte;
    int left_middle_byte;
    int right_middle_byte;
    int rightmost_byte;
    int result;
    leftmost_byte = (value & 0x000000FF) >> 0;
    left_middle_byte = (value & 0x0000FF00) >> 8;
 	right_middle_byte = (value & 0x00FF0000) >> 16;
 	rightmost_byte = (value & 0xFF000000) >> 24;
 	leftmost_byte <<= 24;
 	left_middle_byte <<= 16;
 	right_middle_byte <<= 8;
 	rightmost_byte <<= 0;
 	result = (leftmost_byte | left_middle_byte | right_middle_byte | rightmost_byte);
    printf("Value After Converting = 0x%x\n", result);
    
    return 0;
}
