#include <stdio.h>

float RaiseByPower(float x, int y)
{
    float res = 1;

    if (y < 0)
    {
        x = 1/x;
        y *= -1;
    }

    for (; y > 0; --y)
    {
        res *= x;
    }

    return res;
}

int main(void)
{
    printf("2^2 = %.2f\n", RaiseByPower(2,2));
    printf("2^-2 = %.2f\n", RaiseByPower(2,-2));
    printf("-2^2 = %.2f\n", RaiseByPower(-2,2));
    printf("2^0 = %.2f\n", RaiseByPower(2,0));
    printf("0^2 = %.2f\n", RaiseByPower(0,2));

    return 0;
}

