/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>

int fibIter(int i)
{
    int prev = 0, res = 1;

    for (; i > 1; --i)
    {
        int temp = res;
        res += prev;
        prev = temp;
    }

    return res;
}

int fibRec(int i)
{
    if (i < 2)
    {
        return i;
    }

    return fibRec(i - 1) + fibRec(i - 2);
}

int main(void)
{
    printf("%d\n", fibIter(5));
    printf("%d\n", fibRec(5));

    return 0;
}
