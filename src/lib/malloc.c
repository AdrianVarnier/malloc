#include "malloc.h"

void*   ft_malloc(size_t size)
{
    void* block = NULL;
    size =  ((size + 32 + 15) & ~15);
    size_t heap_flags = get_heap_flags1(size);
    if (heap_flags & ~LARGE)
    {
        for (t_header* heap = g_heap; heap != NULL; heap = heap->next)
        {
            if (heap->flags & heap_flags)
                if ((block = search_free_block(heap, size)) != NULL)
                    return (alloc_block(block, size));
        }
    }
    size_t heap_size = get_heap_size(size);
    t_header* new_heap = alloc_heap(heap_size);
    if (new_heap == NULL)
        return (NULL);
    block = search_free_block(new_heap, size);
    return (alloc_block(block, size));
}