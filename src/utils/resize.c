#include "malloc.h"

// decrease 'block' size to 'size' bytes and update adjacent free block
void    decrease_block1(t_header* block, size_t size)
{
    size_t offset = block->size - size;
    block->size -= offset;
    t_header tmp = *block->next;
    t_header* new = INC_HEADER(block, size);
    *new = tmp;
    new->size += offset;
    new->prev->next = new;
    if (new->next != NULL)
        new->next->prev = new;
    t_header* heap = search_heap(block);
    heap->size += offset;
}

// decrease 'block' size to 'size' bytes and create a free block with the offset
void    decrease_block2(t_header* block, size_t size)
{
    size_t offset = block->size - size;
    block->size -= offset;
    t_header* new = INC_HEADER(block, size);
    new->size = offset;
    new->flags = 0;
    new->flags = FREE;
    new->prev = block;
    new->next = block->next;
    block->next->prev = new;
    block->next = new;
    t_header* heap = search_heap(block);
    heap->size += offset;
}

// increase 'block' size to 'size' bytes and update adjacent free block
void    increase_block(t_header* block, size_t size)
{
    size_t offset = size - block->size;
    block->size += offset;
    t_header tmp = *block->next;
    t_header* new = INC_HEADER(block, size);
    *new = tmp;
    new->size -= offset;
    new->prev->next = new;
    if (new->next != NULL)
        new->next->prev = new;
    t_header* heap = search_heap(block);
    heap->size -= offset;
}