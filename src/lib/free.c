#include "malloc.h"

void    ft_free(void* ptr)
{
    if (ptr)
    {
        t_header* block = search_block(ptr);
        if (block)
        {
            t_header* heap = search_heap(block);
            if (heap->flags & ~LARGE)
            {
                heap->size += block->size;
                dealloc_block(block);
                block = INC_HEADER(heap, HEADER);
                if (INC_HEADER(heap, HEADER)->next == NULL)
                    dealloc_heap(heap);
            }
            else
                dealloc_heap(heap);
        }
    }
}