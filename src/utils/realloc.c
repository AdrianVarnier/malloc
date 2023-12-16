#include "malloc.h"

void*   realloc_block(void* ptr, size_t size)
{
    void* new_ptr = inner_malloc(size);
    if (new_ptr == NULL)
        return (NULL);
    ft_memcpy(new_ptr, ptr, get_ptr_size(ptr));
    inner_free(ptr);
    return (new_ptr);
}