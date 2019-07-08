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
    
    char salt[3], key[5] = "\0\0\0\0\0";
    salt[0] = str[0];
    salt[1] = str[1];
    salt[2] = '\0';
    char *crypt1 = malloc(sizeof(char)*13);
    
    for (int i=0; i<=58; i++)
    {
        if (i==0)
        {
            key[3] = '\0';
        }
        else
        {
            int temp3 = i+64;
            if (temp3>90 && temp3<97)
            {
                continue;
            }
            key[3]=temp3;
        }
        for (int j=0; j<=58; j++)
        {
            if (j==0)
            {
                key[2] = '\0';
            }
            else
            {
                int temp2 = j+64;
                if (temp2>90 && temp2<97)
                {
                    continue;
                }
                key[2] = temp2;
            }
            for (int k=0; k<=58; k++)
            {
                if (k==0)
                {
                    key[1] = '\0';
                }
                else
                {
                    int temp1 = k+64;
                    if (temp1>90 && temp1<97)
                    {
                        continue;
                    }
                    key[1] = temp1;
                }
                for (int l=0; l<=57; l++)
                {
                    int temp = l+65;
                    if (temp>90 && temp<97)
                    {
                        continue;
                    }
                    key[0]=temp;
                    if((strcmp((crypt(key, salt)),str))==0)
                    {
                        printf("%s\n", key);
                        free(crypt1);
                        return 0;
                    }
                }
            }
        }
    }
    printf("\nPassword not found");
    free(crypt1);
}
