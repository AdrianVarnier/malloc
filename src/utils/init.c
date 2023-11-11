#include "malloc.h"

// initialize block of 'size' bytes
void    init_block(t_header* block, size_t size)
{
    block->size = size;
    block->flags = 0;
    block->flags |= FREE;
    block->prev = NULL;
    block->next = NULL;
}

// initialize heap of 'size' bytes
void    init_heap(t_header* heap, size_t size)
{
    heap->size = size - HEADER;
    heap->flags = 0;
    heap->flags |= get_heap_flags2(size);
    heap->prev = NULL;
    heap->next = NULL;
}