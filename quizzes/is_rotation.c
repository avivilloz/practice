#include <stdio.h>
#include <string.h>

int IsRotation(const char *str1, const char *str2)
{
    int size = strlen(str1);
    for (int i = 0; i < size; ++i)
    {
        int j = 0, k = i;

        for (; j < size && str1[j] == str2[k]; ++j, k = (k + 1) % size)
        {} 

        if (j == size)
        {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    const char *str1 = "12345";
    const char *str2 = "45123";
    const char *str3 = "54123";

    printf("%d -> should be 1\n", IsRotation(str1, str2));
    printf("%d -> should be 0\n", IsRotation(str1, str3));

    return 0;
}