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

    for (t_header* p = g_heap + HEADER; p != NULL; p = p->next)
        printf("size: %ld, flags: %ld\naddr: %p, prev: %p, next: %p\n", p->size, p->flags, p, p->prev, p->next);
    printf("\n");

    for (t_header* p = g_heap + HEADER; p != NULL; p = p->next)
        printf("size: %ld, flags: %ld\naddr: %p, prev: %p, next: %p\n", p->size, p->flags, p, p->prev, p->next);
    printf("\n");
    
    return (0);
}