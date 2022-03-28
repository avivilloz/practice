#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(int *arr1, int size1, int *arr2, int size2, int *sorted_arr, int overall_size)
{
    int i = 0;
    int j = 0;

    for (int k = 0; k < overall_size; ++k)
    {
        if ((j >= size2) || ((arr1[i] <= arr2[j]) && (i < size1)))
        {
            sorted_arr[k] = arr1[i];
            ++i;
        }
        else
        {
            sorted_arr[k] = arr2[j];
            ++j;
        }
    }

    memcpy(arr1, sorted_arr, overall_size * sizeof(int));
}

void MergeSortRecursive(int *arr, int size, int *sorted_arr)
{
    if (size < 2)
    {
        return;
    }

    int size1 = size / 2;
    int size2 = size1 + (size % 2);
    int *arr2 = arr + size1;
    int *sorted_arr2 = sorted_arr + size1;

    MergeSortRecursive(arr, size1, sorted_arr);
    MergeSortRecursive(arr2, size2, sorted_arr2);

    Merge(arr, size1, arr2, size2, sorted_arr, size);
}

int MergeSort(int *arr, int size)
{
    int *sorted_arr = (int *)malloc(size * sizeof(int));
    if (NULL == sorted_arr)
    {
        return 1;
    }

    MergeSortRecursive(arr, size, sorted_arr);

    free(sorted_arr);
    sorted_arr = NULL;

    return 0;
}

int main(void)
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};

    MergeSort(arr, 10);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}