/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>

void DLLInsert(DLL *l, void *value)
{
    l->tail->next = DLLCreateNode(value)
    l->tail->next->next = l->tail->next;
    l->tail = l->tail->next;
}

void DLLRemove(DLL *l, DLLNode *node)
{
    if (l->tail == node)
    {
        l->tail = node->prev;
        node->prev->next = node->next;
    }
    else if(l->head == node)
    {
        l->head = node->next;
        node->next->prev = node->prev;
    }
    else
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    DLLDeleteNode(node);
}

int main(void)
{

    return 0;
}
