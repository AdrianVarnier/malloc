#include "malloc.h"

static void insert_heap(t_header* heap)
{
    if (g_heap == NULL)
        g_heap = heap;
    else
    {
        t_header* i = g_heap;
        while (i->next != NULL)
            i = i->next;
        i->next = heap;
        heap->prev = i;
    }
}

static void set_flags(t_header* heap, size_t size)
{
    if (size == TINY_HEAP)
        heap->flags |= TINY;
    else if (size == SMALL_HEAP)
        heap->flags |= SMALL;
    else
        heap->flags |= LARGE;
}

static void set_block(t_header *heap)
{
    t_header* block = INC_HEADER(heap, HEADER);
    block->size = heap->size;
    block->flags = 0;
    block->flags |= FREE;
    set_flags(block, heap->size + HEADER);
    block->prev = NULL;
    block->next = NULL;
}

t_header*   alloc_heap(size_t size)
{
    t_header* heap = mmap(NULL, size, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANON, -1, 0);
    if (heap == MAP_FAILED)
        return (NULL);
    heap->size = size - HEADER;
    heap->flags = 0;
    heap->prev = NULL;
    heap->next = NULL;
    set_flags(heap, size);
    set_block(heap);
    insert_heap(heap);
    return (heap);
}