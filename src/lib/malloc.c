#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>

static size_t get_heap_flags(size_t size)
{
    if (size <= TINY_BLOCK)
        return (TINY);
    else if (size <= SMALL_BLOCK)
        return (SMALL);
    return (LARGE);
}

static size_t get_heap_size(size_t size)
{
    if (size <= TINY_BLOCK)
        return (TINY_HEAP);
    else if (size <= SMALL_BLOCK)
        return (SMALL_HEAP);
    return (size + HEADER);
}

void*   ft_malloc(size_t size)
{
    void* ptr = NULL;
    size =  ((size + 32 + 15) & ~15);
    size_t heap_flags = get_heap_flags(size);
    if (heap_flags & ~LARGE)
    {
        for (t_header* i = g_heap; i != NULL; i = i->next)
        {
            if (i->flags & heap_flags)
                if ((ptr = search_block(i, size)) != NULL)
                    return (ptr);
        }
    }
    size_t heap_size = get_heap_size(size);
    t_header* heap = alloc_heap(heap_size);
    if (heap == NULL)
        return (NULL);
    ptr = search_block(heap, size);
    return ((void *)ptr);
}