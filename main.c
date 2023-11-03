#include "malloc.h"
#include <string.h>

int main()
{
    ft_malloc(1);
    ft_malloc(2);
    ft_malloc(3);
    ft_malloc(4);
    ft_malloc(5);
    ft_malloc(6);
    ft_malloc(7);
    ft_malloc(8);
    ft_malloc(9);

    // if (g_heap->flags & TINY)
    //     printf("tiny heap\n");
    // printf("%ld, %d, %d\n", g_heap->size + HEADER, TINY_HEAP, getpagesize() * 4);

    // for (t_header* p = g_heap + HEADER; p != NULL; p = p->next)
    //     printf("size: %ld, flags: %ld\naddr: %p, prev: %p, next: %p\n", p->size, p->flags, p, p->prev, p->next);
    // printf("\n");

    // size_t size = 10000;
    // t_header* block = g_heap + HEADER;
    // while (block->next != NULL)
    //     block = block->next;
    // t_header* new = block + size;
    // new->size = block->size - size;
    // new->flags = 0;
    // new->flags |= FREE;
    // new->prev = block;
    // new->next = NULL;
    // block->next = new;
    // block->flags ^= FREE;
    // block->size = size;
    // g_heap->size -= size;

    // for (t_header* p = g_heap + HEADER; p != NULL; p = p->next)
    //     printf("size: %ld, flags: %ld\naddr: %p, prev: %p, next: %p\n", p->size, p->flags, p, p->prev, p->next);
    // printf("\n");

    int x = 120;
    void* p = g_heap;
    for (size_t i = 0; i <= 4096 * 4 + x; i++)
    {
        printf("%ld", i);
        ((char *)p)[0] = 'a'; 
    }

    p = g_heap;
    for (size_t i = 0; i <= 4096 * 4 + x; i++)
    {
        printf("%ld", i);
        printf(" %c\n", ((char *)p)[0]);
    }
    
    return (0);
}