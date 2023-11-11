#include "malloc.h"

// search heap corresponding to the given block
t_header*   search_heap(t_header* block)
{
    t_header* i = block;
    while (i->prev != NULL)
        i = i->prev;
    return (DEC_HEADER(i, HEADER));
}

// search free block of 'size' bytes in 'heap'
t_header*   search_free_block(t_header* heap, size_t size)
{
    for (t_header* block = INC_HEADER(heap, HEADER); block != NULL; block = block->next)
    {
        if  (block->flags & FREE)
            if (block->size >= size)
                return (block);
    }
    return (NULL);
}

// search the block corresponding to 'ptr' in the heap list
t_header*   search_block(void* ptr)
{
    for (t_header* heap = g_heap; heap != NULL; heap = heap->next)
        for (t_header* block = INC_HEADER(heap, HEADER); block != NULL; block = block->next)
            if (!(block->flags & FREE))
                if (INC_HEADER(block, HEADER) == ptr)
                    return (block);
    return (NULL);
}