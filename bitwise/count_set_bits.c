#include <stdio.h>

int CountSetBits(unsigned long n)
{
    int count = 0;

    while (n != 0)
    {
        if (n & 1)
        {
            ++count;
        }

        n >>= 1;
    }
    
    return count;
}

int main(void)
{
    printf("%d\n", CountSetBits(15));

    return 0;
}
