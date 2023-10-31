#include "malloc.h"

void* search_heap(size_t size)
{
    size_t  max_size;
    char    flag;
    if (size <= TINY_BLOCK)
    {
        max_size = TINY_HEAP;
        flag |= TINY;
    }
    if (size <= SMALL_BLOCK)
    {
        max_size = SMALL_HEAP;
        flag |= SMALL;
    }

    t_heap* heap = g_heap;
    while (heap != NULL)
    {
        if (heap->flags & flag)
        {
            t_block* block = (t_block*)(heap + HEAP_SIZE);
            t_block* last = block;
            while (block->next != NULL)
            {
                if (block->flags & FREE && size <= block->size)
                {
                    return ((void *)(block + BLOCK_SIZE));
                }
                last = block;
                block = block->next;
            }
            if (heap->size + size + BLOCK_SIZE <= max_size)
            {
                block += BLOCK_SIZE + last->size;
                block->size = size;
                block->flags = 0;
                block->prev = last;
                block->next = NULL;
                heap->size += size + BLOCK_SIZE;
                return ((void *)(block + BLOCK_SIZE));

            }
        }
        heap = heap->next;
    }
    return (NULL);
}