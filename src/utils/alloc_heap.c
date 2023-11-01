#include "malloc.h"

void    insert_heap(t_header* heap)
{
    if (g_heap == NULL)
        g_heap = heap;
    else
    {
        t_header* h = g_heap;
        while (h->next != NULL)
            h = h->next;
        h->next = heap;
        heap->prev = h;
    }
}

void    set_flags(t_header* heap, size_t size)
{
    if (size == TINY_HEAP)
        heap->flags |= TINY;
    else if (size == SMALL_HEAP)
        heap->flags |= SMALL;
    else
        heap->flags |= LARGE;
}

t_header*   alloc_heap(size_t size)
{
    t_header* heap = mmap(NULL, size, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANON, -1, 0);
    heap->size = size;
    heap->flags = 0;
    heap->prev = NULL;
    heap->next = NULL;
    set_flags(heap, size);
    insert_heap(heap);
    return (heap);
}