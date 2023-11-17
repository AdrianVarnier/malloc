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
    char *tiny = malloc(17);
    strcpy(tiny, "0123456789abcdef");
    char *small = malloc(161);
    for (size_t i = 0; i != 10; i++)
        strcpy(small + i * 16, tiny);
    printf("%s\n%s\n", tiny, small);
    show_alloc_mem();
    return (0);
}