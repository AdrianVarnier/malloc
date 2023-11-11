#include "malloc.h"

void*   ft_realloc(void* ptr, size_t size)
{
    void* new_ptr = ft_malloc(size);
    ft_memcpy(new_ptr, ptr, size);
    ft_free(ptr);
    return(new_ptr);
}