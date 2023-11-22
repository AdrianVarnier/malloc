#include "malloc.h"

void*   inner_realloc(void* ptr, size_t size)
{
    if (!ptr)
        return (inner_malloc(size));
    if (!size)
    {
        inner_free(ptr);
        return (NULL);
    }

    t_header* block = search_block(ptr);
    if (!block)
        return (NULL);

    if (search_heap(block)->flags & LARGE)
        return (realloc_block(ptr, size));

    size_t new_size =  ((size + 32 + 15) & ~15);
    if (new_size < block->size)
    {
        if (block->next != NULL && (block->next->flags & FREE))
            decrease_block1(block, new_size);
        else if (block->next != NULL && !(block->next->flags & FREE)
        && block->size - new_size > HEADER)
            decrease_block2(block, new_size);
    }
    else if (new_size > block->size)
    {
        if (block->next != NULL && (block->next->flags & FREE)
        && new_size - block->size <= block->next->size - HEADER)
            increase_block(block, new_size);
        else
            return (realloc_block(ptr, size));
    }
    return (ptr);
}

void*   realloc(void* ptr, size_t size)
{
    pthread_mutex_lock(&g_mutex);
    ptr = inner_realloc(ptr, size);
    pthread_mutex_unlock(&g_mutex);
    return (ptr);
}