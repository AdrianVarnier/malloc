#include "malloc.h"

void    free_block(t_header* block)
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
    ft_memset(INC_HEADER(l, HEADER), 0, l->size - HEADER);
}