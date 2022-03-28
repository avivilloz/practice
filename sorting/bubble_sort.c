#include <stdio.h>

void BubbleSort(int *arr, int size)
{
    int sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        for (int i = 0, j = 1; j < size; ++i, ++j)
        {
            if (arr[i] > arr[j])
            {
                sorted = 0;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};

    BubbleSort(arr, 10);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}