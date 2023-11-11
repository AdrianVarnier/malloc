#include "malloc.h"

// allocate 'size' bytes in 'block'
void*   alloc_block(t_header* block, size_t size)
{
    if (block->size - size >= HEADER)
    {
        t_header* new = INC_HEADER(block, size);
        new->size = block->size - size;
        new->flags = 0;
        new->flags = FREE;
        new->prev = block;
        new->next = NULL;
        block->next = new;
        block->size = size;
    }
    block->flags &= ~FREE;
    t_header* heap = search_heap(block);
    heap->size -= size;
    return (INC_HEADER(block, HEADER));
}

// allocate heap of 'size' bytes
t_header*   alloc_heap(size_t size)
{
    t_header* heap = mmap(NULL, size, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANON, -1, 0);
    if (heap == MAP_FAILED)
        return (NULL);
    init_heap(heap, size);
    init_block(INC_HEADER(heap, HEADER), heap->size);
    if (g_heap == NULL)
        g_heap = heap;
    else
    {
        t_header* last_heap = get_last_heap();
        last_heap->next = heap;
        heap->prev = last_heap;
    }
    return (heap);
}