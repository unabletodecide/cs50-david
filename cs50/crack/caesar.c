#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("Error\n");
        return 1;
    }
    
    char *plaintext = get_string("plaintext: ");
    long k1 = atol(argv[1]);
    int n = strlen(plaintext);
    int temp, flag;
    int k= (int)k1%26;
    //char *ctext = malloc(sizeof(char)*n); 
    printf("ciphertext: ");
    for (int i=0; i<n; i++)
    {
        if (plaintext[i]>=97 & plaintext[i]<122)
        {
            flag=0;
        }
        else
        {
            flag=1;
        }
        temp = plaintext[i] + k;
        if ((temp>122 && flag==0) || (temp > 90 && flag ==1))
        {
            temp = temp-26;
        }
        printf("%c", (char)temp);
    }
}