#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Enter Card Number: ");
    }
    while(card<0);
    // printf("Enter Card Number: ");
    // scanf("%lld",&card);
    int n, i=0;
    long temp;
    char *s ;
    s = (char*)malloc(sizeof(char));
    while (card>0)
    {
        temp = (int)(card%10);
        card = card/10;
        s[i] = temp+'0';
        i++;
        s = (char*)realloc(s, sizeof(char)*(i+1));
    }
    
    int size = strlen(s), sum1=0, sum2=0;
    /*
    char tempi;
    for (int k=0; k<size; k++)
    {
        tempi = s[size-k-1];
        printf("%c",tempi);
    }
    printf("outsidew loop");
    free(s);
    */
    for (int j=0; j<size; j++)
    {
        if (j%2==0)
        {
            sum2+=((int)(s[j])-'0');
        }
        else
        {
            int temp1 = (2*(int)(s[j]-'0'));
            if (temp1/10 == 0)
            {
                sum1+=temp1;
            }
            else
            {
                int temp3 = temp1/10;
                int temp2 = temp1%10;
                sum1 += (temp2+temp3);
            }
        }
    }
    if ((sum1+sum2)%10==0)
    {
        printf("Valid");
    }
    else
    {
        printf("Invalid");
    }
}