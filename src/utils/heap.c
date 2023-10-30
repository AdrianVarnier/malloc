#include "malloc.h"

static void set_flags(t_heap* heap, size_t size)
{
    if (size == TINY_HEAP)
        heap->flags = TINY;
    if (size == SMALL_HEAP)
        heap->flags = SMALL;
    else
        heap->flags = LARGE;
}

static void insert_heap(t_heap* heap)
{
    if (g_heap == NULL)
    {
        g_heap = heap;
        heap->prev = NULL;
    }
    else
    {
        t_heap* i = g_heap;
        while (i->next != NULL)
            i = i->next;
        i->next = heap;
        heap->prev = i;
    }
    heap->next = NULL;
}

t_heap* create_heap(size_t size)
{
    t_heap* heap = (t_heap*)mmap(NULL, size,
        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    set_flags(heap, size);
    insert_heap(heap);
    return (heap);
}