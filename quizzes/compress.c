/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void WordCompress(char *str)
{
    int count = 1;
    char curr_c = *str;
    for (++str; *str != '\0'; ++str)
    {
        if (*str == curr_c)
        {
            ++count;
        }
        else
        {
            printf("%c%d", curr_c, count);
            count = 1;
            curr_c = *str;
        }
    }
    printf("%c%d\n", curr_c, count);
}

int main(void)
{
    WordCompress("HARRY");
    WordCompress("ccccOddEEE");
    WordCompress("RANDER");

    return 0;
}
