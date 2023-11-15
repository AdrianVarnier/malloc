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
    char *s[5];
    s[0] = ft_malloc(64);
    s[1] = ft_malloc(64);
    s[2] = ft_malloc(64);
    ft_free(s[1]);
    print_heap();
    ft_realloc(s[0], 16);
    print_heap();
    return (0);
}