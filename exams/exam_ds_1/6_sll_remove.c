/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>

void SLLRemove(SLLNode *node_to_remove)
{
    SLLNode *next_node = node_to_remove->next;

    node_to_remove->value = next_node->value;
    node_to_remove->next = next_node->next;

    free(next_node);
    next_node = NULL;
}

int main(void)
{

    return 0;
}
