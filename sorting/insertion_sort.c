#include <stdio.h>

void InsertionSort(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i, k = i - 1; j > 0; --j, --k)
        {
            if (arr[k] > arr[j])
            {
                int temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

int main(void)
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};

    InsertionSort(arr, 10);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}