#define _XOPEN_SOURCE
#include <unistd.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        printf("Error");
        return 1;
    }
    
    char *str;
    str = argv[1];
    
    char salt[3], key[5] = "rofl";
    memcpy(salt, str, 2);
    salt[2] = '\0';
    printf("%s", salt);
    printf("\n%s",key);
    char *crypt1 = malloc(sizeof(char)*13);
    crypt1 = crypt(key, salt);
    printf("%s", crypt1);
}