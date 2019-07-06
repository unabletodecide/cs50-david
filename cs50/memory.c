#include <stdlib.h>
#include <stdio.h>
void f(void);

int main(void)
{
    f();
}

void f(void)
{
    char *x = malloc(2 * sizeof(char));
    x[0]='s';
    x[1]='a';
    printf("You printed %c %c", x[0], x[1]);
    free(x);
}