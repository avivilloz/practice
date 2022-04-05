/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>

void SLLOpenLoop(SLLNode *head)
{
    // first find the loop
    SLLNode *run = head;
    SLLNode *run_faster = head;
    while (run != run_faster)
    {
        run = run->next;
        run_faster = run_faster->next->next;
    }

    // find loop intersection
    SLLNode *run_slow = head;
    while (run->next != run_slow->next)
    {
        run = run->next;
        // run_faster now doesn't move and only serves as reference to know that run_slow is not about to enter the loop
        if (run == run_faster)
        {
            run_slow = run_slow->next;
        }
    }

    // open the loop
    run->next = NULL;
}

int main(void)
{

    return 0;
}
