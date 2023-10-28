#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>

void*   ft_malloc(size_t size)
{
    if (heap == NULL)
    {
        printf("null heap\n");
        heap = malloc(sizeof(t_heap));
    }
    else
        printf("full heap\n");
    return (NULL);
}