/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>

int SLLHasLoop(SLLNode *head)
{
    SLLNode *run = head;
    SLLNode *run_faster = head;

    while (run_faster != NULL && run_faster->next != NULL)
    {
        run = run->next;
        run_faster = run_faster->next->next;

        if (run_faster == run)
        {
            return 1;
        }
    }

    return 0;
}

int main(void)
{

    return 0;
}
