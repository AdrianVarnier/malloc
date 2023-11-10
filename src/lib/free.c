#include "malloc.h"

int search_ptr(void* ptr)
{
    for (t_header* heap = g_heap; heap != NULL; heap = heap->next)
        for (t_header* block = INC_HEADER(heap, HEADER); block != NULL; block = block->next)
            if (block->flags & ~FREE)
                if (INC_HEADER(block, HEADER) == ptr)
                    return (1);
    return (0);
}

void    ft_free(void* ptr)
{
    if (ptr)
    {
        if (search_ptr(ptr))
        {
            t_header* block = DEC_HEADER(ptr, HEADER);
            t_header* heap;
            for (t_header* heap = block; heap != NULL; heap = heap->prev)
                if (heap->prev == NULL)
                    heap = DEC_HEADER(heap, HEADER)->size;
            heap->size += block->size;
            if (block->flags & LARGE)
                munmap(ptr, block->size + HEADER);
            else
            {
                free_block(block);
                block = INC_HEADER(heap, HEADER);
                if (block->next == NULL && (block->flags & FREE))
                    free_heap(heap);
            }
        }
    }
}