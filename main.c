#include "malloc.h"
#include <string.h>
#include <stdlib.h>

void print_heap(void)
{
    if (g_heap == NULL)
        printf("empty heap");
    else
        for (t_header* i = INC_HEADER(g_heap, HEADER); i != NULL; i = i->next)
            printf("%ld %ld\n", i->size, i->flags);
    printf("\n");
}

int main()
{
    ft_malloc(148);
    ft_malloc(400);
    ft_malloc(20);
    ft_malloc(10000);
    show_alloc_mem();
    return (0);
}