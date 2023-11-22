#include "malloc.h"

void*   realloc_block(void* ptr, size_t size)
{
    size_t new_size =  ((size + 32 + 15) & ~15);
    void* new_ptr = inner_malloc(size);
    if (new_ptr == NULL)
        return (NULL);
    ft_memcpy(new_ptr, ptr, new_size);
    inner_free(ptr);
    return (new_ptr);
}