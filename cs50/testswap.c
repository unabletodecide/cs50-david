#include <stdio.h>
#include "struct.h"
void swap(int *x, int *y);
int main(void)
{
    int a =10;
    int b = 11;
    
    swap(&a, &b);
    
    
    
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("First number is now %i \nSecond number is now %i", *x, *y);
}