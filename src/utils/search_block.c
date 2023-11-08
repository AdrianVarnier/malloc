#include "malloc.h"

static void    alloc_block(t_header* block, size_t size)
{
    t_header* new = (t_header*)((char*)block + size);
    new->size = block->size - size;
    new->flags = 0;
    new->flags |= FREE;
    new->prev = block;
    new->next = NULL;
    block->next = new;
}

t_header*   search_block(t_header* heap, size_t size)
{
    for (t_header* i = heap + HEADER; i != NULL; i = i->next)
    {
        if  (i->flags & FREE)
            if (i->size >= size)
            {
                if (i->size - size >= HEADER)
                {
                    alloc_block(i, size);
                    i->size = size;
                }
                i->flags ^= FREE;
                heap->size -= size;
                return (i + HEADER);
            }
    }
    return (NULL);
}