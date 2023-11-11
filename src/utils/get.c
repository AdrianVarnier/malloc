#include "malloc.h"

// return the heap flag on the given block size
size_t  get_heap_flags1(size_t size)
{
    if (size <= TINY_BLOCK)
        return (TINY);
    else if (size <= SMALL_BLOCK)
        return (SMALL);
    return (LARGE);
}

// return the heap flag on the given heap size
size_t  get_heap_flags2(size_t size)
{
    if (size == TINY_HEAP)
        return (TINY);
    else if (size == SMALL_HEAP)
        return (SMALL);
    return (LARGE);
}

// return the size of the heap on the given block size
size_t  get_heap_size(size_t size)
{
    if (size <= TINY_BLOCK)
        return (TINY_HEAP);
    else if (size <= SMALL_BLOCK)
        return (SMALL_HEAP);
    return (size + HEADER);
}

// return the last heap in heap list
t_header*   get_last_heap(void)
{
    t_header* heap = g_heap; 
    while (heap != NULL)
        heap = heap->next;
    return (heap);
}