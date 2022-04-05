/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *ReverseString(char *str)
{
    char *runner = str;

    for (; *runner; ++runner)
    {
        int word_size = 0;
        int count = 0;

        while (runner[count] == ' ')
        {
            ++count;
        }

        while (runner[count] && runner[count] != ' ')
        {
            ++count;
            ++word_size;
        }

        for (int i = 0, j = count - 1; i < j; ++i, --j)
        {
            char temp = runner[i];
            runner[i] = runner[j];
            runner[j] = temp;
        }

        printf("%s\n", str);
        runner += word_size;
        sleep (1);
    }

    return str;
}

int main(void)
{
    char *str = (char *)malloc(100);
    strcpy(str, "  hi   my name   is   aviv   ");
    printf("%s\n", ReverseString(str));
    return 0;
}
