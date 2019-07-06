#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // int numbers[50]; -- Cannot do that, user might want to enter 51
    //Array is a chunk of memory
    
    int *numbers = NULL; //numbers really is just a pointer to the chunk of memory, there is no array; this pointer points to 0x00.
    // you can point this pointer to any chunk of memory, small or big
    
    int capacity=0;
    int size=0;
    
    while (true)
    {
        int number = get_int("Number: ");        // Get number from human.
        
        if (number == INT_MAX)   //EOF or Ctrl+D by user
        {
            break;
        }
        
        if (size == capacity)
        {
            numbers = realloc(numbers, sizeof(int) * (size + 1));
            capacity++;
            //if realloc fails to allocate memory, that's why we take it in a temp pointer and check
            // allocate the pointer to a bigger memory heap, return new address of the chunk of memory
        }
        
        numbers[size] = number;
        size++;
    }
    for (int i = 0; i<size; i++)
    {
        printf("You inputted %i\n", numbers[i]);
    }
        
    free(numbers);
}