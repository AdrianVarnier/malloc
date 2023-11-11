#include "malloc.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    char *s[5];
    for (size_t i = 0; i < 5; i++)
        s[i] = ft_malloc(3);
    ft_free(s[1]);
    ft_free(s[3]);
    ft_free(s[2]);
    ft_free(s[0]);
    ft_free(s[4]);
    if (g_heap == NULL)
        printf("empty heap");
    else
        for (t_header* i = INC_HEADER(g_heap, HEADER); i != NULL; i = i->next)
            printf("%ld %ld\n", i->size, i->flags);
    printf("\n");
    return (0);
}