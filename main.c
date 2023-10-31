#include "malloc.h"
#include <stdio.h>

int main()
{
    t_heap* h = NULL;
    t_block* b = NULL;

    h = create_heap(TINY_HEAP);
    b = search_heap(TINY_BLOCK);
    printf("%lu\n", 2 * (BLOCK_SIZE + TINY_BLOCK) + HEAP_SIZE);
    if (b != NULL)
        printf("%ld, %d, %p, %p, %ld\n", b->size, b->flags, b->prev, b->next, h->size);
    else
        printf("null\n");

    b = search_heap(SMALL_BLOCK);
    if (b != NULL)
        printf("%ld, %d, %p, %p, %ld\n", b->size, b->flags, b->prev, b->next, h->size);
    else
        printf("null\n");
    
    b = search_heap(TINY_BLOCK);
    if (b != NULL)
        printf("%ld, %d, %p, %p, %ld\n", b->size, b->flags, b->prev, b->next, h->size);
    else
        printf("null\n");
    
    return (0);
}