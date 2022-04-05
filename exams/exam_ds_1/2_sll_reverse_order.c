/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>

SLLNode *SLLReverse(SLLNode *head)
{
    if (NULL == head)
    {
        return NULL;
    }

    SLLNode *curr = head->next;
    head->next = NULL;

    while (NULL != curr)
    {
        SLLNode *next = curr->next;
        curr->next = head;

        head = curr;
        curr = next;
    }

    return head;
}

int main(void)
{

    return 0;
}
