#include "malloc.h"

// deallocate 'heap' and remove it from heap list
void    dealloc_heap(t_header* heap)
{
    if (heap->prev != NULL)
        heap->prev->next = heap->next;
    if (heap->next != NULL)
        heap->next->prev = heap->prev;
    if (heap->prev == NULL)
        g_heap = heap->next;
    if (heap->flags & LARGE)
        heap->size = INC_HEADER(heap, HEADER)->size + HEADER;
    munmap(heap, heap->size + HEADER);
}

// deallocate 'block' and merge the adjacent free block
void    dealloc_block(t_header* block)
{
    t_header* l = block;
    t_header* r = block;
    if (block->prev != NULL && (block->prev->flags & FREE))
        l = block->prev;
    if (block->next != NULL && (block->next->flags & FREE))
        r = block->next;
    l->next = r->next;
    if (r->next != NULL)
        r->next->prev = l;
    l->flags |= FREE;
    if (l != r)
        l->size += r->size;
    if (l != block && r != block)
        l->size += block->size;
}