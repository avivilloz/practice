/*****************************************************************************
 * title: 
 * description:
 * author: aviv illoz
*****************************************************************************/

#include <stdio.h>

typedef struct vsa
{
    unsigned int vsa_size;
    unsigned int first_free_header;
} vsa_t;

typedef struct vsa_header
{
    unsigned int block_size;
    unsigned int next_free_header_or_vsa;
}

void *Malloc(vsa_t *vsa)
{
    if (0 == vsa.first_free_header)
    {
        return NULL;
    }

    vsa_header_t *block_header = (vsa_header_t *)((unsigned char*)vsa + vsa.first_free_header);
    void *block = (void *)(block_header + 1);

    unsigned int vsa = vsa.first_free_header;
    vsa.first_free_header = block_header->next_free_header_or_vsa;
    block_header->next_free_header_or_vsa = vsa;

    return block;
}

void Free(void *block)
{
    vsa_header_t *block_header = (unsigned char*)block - sizeof(vsa_header_t);
    vsa_t vsa = (unsigned char *)block_header - block_header->next_free_header_or_vsa;

    unsigned int next_free_header = vsa.first_free_header;
    vsa.first_free_header = block_header->next_free_header_or_vsa;
    block_header->next_free_header_or_vsa = next_free_header;
}

int main(void)
{

    return 0;
}
