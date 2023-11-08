#include "malloc.h"
#include <string.h>

int main()
{
    for (size_t i = 0; i < 10; i++)
        ft_malloc(16);

    size_t i = 1;
    for (t_header* p = g_heap + HEADER; p != NULL; p = p->next, i++)
        printf("%ld   size: %ld, flags: %ld\naddr: %p, prev: %p, next: %p\n", i, p->size, p->flags, p, p->prev, p->next);
    printf("\n");

    
    return (0);
}