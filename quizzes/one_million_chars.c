#include <stdio.h>

void OneMillionChars(int x)
{
    static char ocurrences_map[255] = {0};

    ++ocurrences_map[x];

    if (0 == x)
    {
        for (int c = 0; c < 255; ++c)
            printf("ocurrences of %c = %d\n", c, ocurrences_map[c]);
    }
}

int main(void)
{
    for (int c = 0; c < 255; ++c)
        OneMillionChars(c);

    OneMillionChars(0);

    return 0;
}
