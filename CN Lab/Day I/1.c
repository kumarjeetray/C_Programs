/*

Write a C program to swap the content of 2 variables entered through thecommand line using function and pointer.

*/

#include <stdio.h>
void swap(int *x, int *y)  
{  
    int temp;  
  
    temp = *x;  
    *x   = *y;  
    *y   = temp;  
}  

int main()  
{  
    int a, b;  
  
    printf("Enter values for a and b\n");  
    scanf("%d%d", &a, &b);  
  
    printf("\n\nBefore swapping: a = %d and b = %d\n", a, b);  
  
    swap(&a, &b);  
  
    printf("\nAfter swapping: a = %d and b = %d\n", a, b);  
  
    return 0;  
}  
