#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    int n = strlen(s);
    for (int i=0; i<=n; i++)
    {
        printf("%c\n", s[i]);
    }
    printf("%s",s);
}