#include <stdio.h>

int InsertPivot(int *arr, int size)
{
    int pivot = 0;

    for (int i = pivot + 1; i < size; ++i)
    {
        if (arr[i] < arr[pivot])
        {
            for (int j = i, k = j - 1; j > pivot; --j, --k)
            {
                int temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
            }
            ++pivot;
        }
    }

    return pivot;
}

void QuickSort(int *arr, int size)
{
    if (size < 2)
    {
        return;
    }

    int pivot = InsertPivot(arr, size);

    QuickSort(arr, pivot);
    QuickSort(arr + pivot, size - pivot);
}

int main(void)
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};

    QuickSort(arr, 10);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}