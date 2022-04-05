/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>

typedef struct fsa
{
    unsigned int first_free_header;
} fsa_t;

typedef struct fsa_header
{
    unsigned int next_free_header_or_fsa;
}

void *Malloc(fsa_t *fsa)
{
    if (0 == fsa.first_free_header)
    {
        return NULL;
    }

    fsa_header_t *block_header = (fsa_header_t *)((unsigned char*)fsa + fsa.first_free_header);
    void *block = (void *)(block_header + 1);

    unsigned int fsa = fsa.first_free_header;
    fsa.first_free_header = block_header->next_free_header_or_fsa;
    block_header->next_free_header_or_fsa = fsa;

    return block;
}

void Free(void *block)
{
    fsa_header_t *block_header = (unsigned char*)block - sizeof(fsa_header_t);
    fsa_t fsa = (unsigned char *)block_header - block_header->next_free_header_or_fsa;

    unsigned int next_free_header = fsa.first_free_header;
    fsa.first_free_header = block_header->next_free_header_or_fsa;
    block_header->next_free_header_or_fsa = next_free_header;
}

int main(void)
{

    return 0;
}
