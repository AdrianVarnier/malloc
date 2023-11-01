#include "malloc.h"
#include <stdio.h>

int main()
{
    t_header*   h = NULL;

    h = alloc_heap(TINY_HEAP);
    t_header* b = h + HEADER;
    alloc_block(b, 11);
    b = b->next;
    alloc_block(b, 22);
    b = b->next;
    alloc_block(b, 33);
    b = b->next;
    alloc_block(b, 44);
    b = b->next;
    alloc_block(b, 55);
    for (t_header* i = h + HEADER; i != NULL; i = i->next)
    {
        if (i->flags & FREE)
            printf("USED: ");
        else
            printf("FREE: ");
        printf("%ld\n", i->size);
    }


    return (0);
}