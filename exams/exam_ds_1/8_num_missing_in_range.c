/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int FindMissingNum(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)    
    {
        count += arr[i];
    }
    return (size * (size + 1) / 2) - count;
}

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

void print(int *array, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

#define SIZE 1024

int main(void)
{
    int arr[SIZE];

    for (int i = 0, value = 0; i < SIZE + 1; ++i, ++value)
    {   
        if (i == 45) // missing num
        {
            ++value;
        }

        arr[i] = value; 
    }    

    shuffle(arr, SIZE);
    print(arr, SIZE);

    printf("%d\n", FindMissingNum(arr, SIZE));

    return 0;
}
