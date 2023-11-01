#include "malloc.h"

void    alloc_block(t_header* block, size_t size)
{
    t_header* new = block + HEADER + block->size;
    new->size = size;
    new->flags = 0;
    new->prev = block;
    new->next = NULL;
    block->next = new;
}