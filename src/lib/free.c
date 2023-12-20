#include "malloc.h"

void    inner_free(void* ptr)
{
    if (ptr)
    {
        t_header* block = search_block(ptr);
        if (block)
        {
            t_header* heap = search_heap(block);
            if (!(heap->flags & LARGE))
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

void    free(void* ptr)
{
    pthread_mutex_lock(&g_mutex);
    inner_free(ptr);
    pthread_mutex_unlock(&g_mutex);
}