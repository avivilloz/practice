#include <stdio.h>

void SelectionSort(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        int selected_iterator = i;

        for (int j = i; j < size; ++j)
        {
            if (arr[selected_iterator] > arr[j])
            {
                selected_iterator = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[selected_iterator];
        arr[selected_iterator] = temp;
    }
}

int main(void)
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};

    SelectionSort(arr, 10);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}