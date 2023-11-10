#include "malloc.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    char *s[256];
    for (size_t i = 0; i < 256; i++)
        s[i] = ft_malloc(TINY_BLOCK - 32);
    for (t_header* p = g_heap; p != NULL; p = p->next)
    {
        size_t n = 0;
        for (t_header *block = INC_HEADER(g_heap, HEADER); block != NULL; block = block->next)
            n++;
        printf("heap size = %ld, with %ld blocks\n", p->size, n);
    }
    printf("\n");
    // printf("size: %ld, flags: %ld\naddr: %p, prev: %p, next: %p\n",
    //         g_heap->size, g_heap->flags, g_heap, g_heap->prev, g_heap->next);
    // size_t i = 1;
    // for (t_header* p = INC_HEADER(g_heap, HEADER); p != NULL; p = p->next, i++)
    //     printf("%ld size: %ld, flags: %ld\naddr: %p, prev: %p, next: %p\n",
    //         i, p->size, p->flags, p, p->prev, p->next);
    // i = 1;
    // for (t_header* p = INC_HEADER(g_heap->next, HEADER); p != NULL; p = p->next, i++)
    //     printf("%ld size: %ld, flags: %ld\naddr: %p, prev: %p, next: %p\n",
    //         i, p->size, p->flags, p, p->prev, p->next);
    // printf("\n");
    for (size_t i = 0; i < 256; i++)
        ft_free(s[i]);
    for (t_header* p = g_heap; p != NULL; p = p->next)
    {
        size_t n = 0;
        for (t_header *block = INC_HEADER(g_heap, HEADER); block != NULL; block = block->next)
            n++;
        printf("heap size = %ld, with %ld blocks\n", p->size, n);
    }
    printf("\n");
    return (0);
}