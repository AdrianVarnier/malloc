#include "malloc.h"
#include <stdio.h>

int main()
{
    t_heap* p;
    p = ft_malloc(10);
    printf("%p: %ld, %ld, %d, %p, %p\n", p, p->size, p->free_size, p->type, p->next, p->prev);
    p += 40;
    printf("%p: %ld, %d, %p, %p\n", (t_block*)p, ((t_block*)p)->size, ((t_block*)p)->free, ((t_block*)p)->prev, ((t_block*)p)->next);
    printf("%ld\n", sizeof(t_block));
    return (0);
}