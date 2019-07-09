#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    int ksize = strlen(argv[1]);
    char *k = argv[1];
    for (int i=0; i<ksize; i++)
    {
        if (isdigit(k[i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    char *input = get_string("plaintext: ");
    int temp;
    int *codes = (int*)(malloc(sizeof(int)*ksize));
    for (int i=0; i<ksize; i++)
    {
        if (k[i]>=97 && k[i]<=122)
        {
            temp = k[i] - 97;
        }
        else if (k[i]>=65 && k[i]<=(65+26))
        {
            temp = k[i] - 65;
        }
        codes[i] = temp;
    }
    // for (int j=0; j<5; j++)
    // {
    //     printf("\n%i", codes[j]);
    // }
    int msize = strlen(input), flag=0, temp2=0, count=0;
    printf("ciphertext: ");
    for (int i=0; i<msize; i++)
    {
        if (input[i]==32)
        {
            printf("%c",input[i]);
            count+=1;
            continue;
        }
        if (input[i]>=97 && input[i]<=122)
        {
            flag=0;
        }
        else if (input[i]>=65 && input[i]<=(65+26))
        {
            flag=1;
        }
        else
        {
            flag=3;
        }
        int index=(i-count)%ksize;
        temp2 = input[i];
        if (flag == 3)
        {
            printf("%c", (char)temp2);
            continue;
        }
        temp2 = input[i] + codes[index];
        if ((temp2>122 && flag==0) || (temp2 > 90 && flag ==1))
        {
            temp2 = temp2-26;
        }
        printf("%c", (char)temp2);
    }
}