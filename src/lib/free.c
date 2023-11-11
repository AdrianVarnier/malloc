#include "malloc.h"

static int  search_ptr(void* ptr)
{
    for (t_header* heap = g_heap; heap != NULL; heap = heap->next)
        for (t_header* block = INC_HEADER(heap, HEADER); block != NULL; block = block->next)
            if (!(block->flags & FREE))
                if (INC_HEADER(block, HEADER) == ptr)
                    return (1);
    printf("not found\n");
    return (0);
}

static t_header*    get_heap(t_header* block)
{
    t_header* i = block;
    while (i->prev != NULL)
        i = i->prev;
    return (DEC_HEADER(i, HEADER));
}

static void free_heap(t_header* heap)
{
    if (heap->prev != NULL)
        heap->prev->next = heap->next;
    if (heap->next != NULL)
        heap->next->prev = heap->prev;
    if (heap->prev == NULL && heap->next == NULL)
        g_heap = NULL;
    munmap(heap, heap->size + HEADER);
}

static void free_block(t_header* block)
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

void    ft_free(void* ptr)
{
    if (ptr)
    {
        if (search_ptr(ptr))
        {
            t_header* block = DEC_HEADER(ptr, HEADER);
            t_header* heap = get_heap(block);
            if (heap->flags & ~LARGE)
            {
                heap->size += block->size;
                free_block(block);
                block = INC_HEADER(heap, HEADER);
                if (INC_HEADER(heap, HEADER)->next == NULL)
                    free_heap(heap);
            }
            else
                free_heap(heap);
        }
    }
}