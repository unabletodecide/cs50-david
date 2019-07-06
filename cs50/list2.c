#include <stdio.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(void)
{
    //Memory for numbers
    node *numbers = NULL;
    
    //Prompt for numbers (until EOF)
    while(true)
    {
        // Prompt for number
        int number = get_int("Number: ");
        
        if (number == INT_MAX)   //cs50 implementation of EOF
        {
            break;
        }
        
        node *n = malloc(sizeof(node));
        if (!n)   //n==NULL
        {
            return 1;
        }
        
        // Add number to list
        n->number = number; // this is the same as saying dereference n (*n).number=number
        n->next = NULL;
        if (numbers)
        {
            for (node *ptr = numbers; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
        else
        {
            numbers = n;
        }
    }
    
    free(numbers);
}