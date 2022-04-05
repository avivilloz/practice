/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>

int SLLHasIntersection(SLLNode *l1_head, SLLNode *l2_head)
{
    for (SLLNode *l1_runner = l1_head; NULL != l1_runner; l1_runner = l1_runner->next)
    {
        for (SLLNode *l2_runner = l2_head; NULL != l2_runner; l2_runner = l2_runner->next)
        {
            if (l1_runner == l2_runner)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main(void)
{

    return 0;
}
