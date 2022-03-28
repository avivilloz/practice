#include <stdio.h>

int BinarySearch(int *sorted_arr, int size, int num_to_find, int *index)
{
    int found = 0;

    int l = 0, r = size - 1; 

    while (l != r)
    {
        int m = ((r - l) / 2) + l;
        if (sorted_arr[m] > num_to_find)
        {
            r = m - 1;
        }
        else if (sorted_arr[m] < num_to_find)
        {
            l = m + 1;
        }
        else
        {
            found = 1;
            *index = m;
            break;
        }
    }

    return found;
}

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9};

    int index = 0;
    printf("found: %d\n", BinarySearch(arr, 10, 9, &index));
    printf("index: %d\n", index);

    return 0;
}