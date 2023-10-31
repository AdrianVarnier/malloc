#include "malloc.h"

static void set_flags(t_heap* heap, size_t size)
{
    heap->flags = 0;
    if (size == TINY_HEAP)
        heap->flags |= TINY;
    else if (size == SMALL_HEAP)
        heap->flags |= SMALL;
    else
        heap->flags |= LARGE;
}

static void set_block(t_block* block)
{
    block->size = 0;
    block->flags |= FREE;
    block->prev = NULL;
    block->next = NULL;
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
    heap->size = HEAP_SIZE + BLOCK_SIZE;
    set_flags(heap, size);
    set_block((t_block*)(heap + HEAP_SIZE));
    insert_heap(heap);
    return (heap);
}