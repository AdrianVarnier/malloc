#include "malloc.h"

void*   inner_malloc(size_t size)
{
    if (size == 0)
        return (NULL);
    void* block = NULL;
    size =  ((size + 32 + 15) & ~15);
    size_t heap_flags = get_heap_flags1(size);
    if (!(heap_flags & LARGE))
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

void*   malloc(size_t size)
{
    pthread_mutex_lock(&g_mutex);
    void* ptr = inner_malloc(size);
    pthread_mutex_unlock(&g_mutex);
    return (ptr);
}