#include "malloc.h"
#include <stdio.h>

int main()
{
    t_header*   h = NULL;

    alloc_heap(TINY_HEAP); 
    alloc_heap(TINY_HEAP); 
    alloc_heap(SMALL_HEAP); 
    alloc_heap(TINY_HEAP);
    alloc_heap(SMALL_HEAP); 
    alloc_heap(SMALL_HEAP + 1);
    alloc_heap(SMALL_HEAP); 
    alloc_heap(SMALL_HEAP + 1);
    alloc_heap(SMALL_HEAP + 1);

    h = g_heap;
    for (t_header *h = g_heap; h != NULL; h = h->next)
    {
        if (h->flags & TINY)
            printf("TINY:  ");
        else if (h->flags & SMALL)
            printf("SMALL: ");
        else
            printf("LARGE: ");
        printf("%ld, %p, %p\n", h->size, h->prev, h->next);
    }

    return (0);
}