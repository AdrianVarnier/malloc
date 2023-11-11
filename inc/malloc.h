#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h> //debug

// size
#define HEADER sizeof(t_header)
#define TINY_HEAP (4 * getpagesize())
#define SMALL_HEAP (16 * getpagesize())
#define TINY_BLOCK 128
#define SMALL_BLOCK 512

#define INC_HEADER(ptr, size) ((t_header *)((char *)ptr + size))
#define DEC_HEADER(ptr, size) ((t_header *)((char *)ptr - size))

// flags
#define TINY (1 << 0)
#define SMALL (1 << 1)
#define LARGE (1 << 2)
#define FREE (1 << 3)

// struct
typedef struct  s_header
{
    size_t              size;
    size_t              flags;
    struct s_header*    prev;
    struct s_header*    next;
}   t_header;

// global
extern t_header*  g_heap;

// lib
void*       ft_malloc(size_t size);
void        ft_free(void* ptr);
void*       ft_realloc(void* ptr, size_t size);

// utils
void*       alloc_block(t_header* block, size_t size);
t_header*   alloc_heap(size_t size);

void        dealloc_heap(t_header* heap);
void        dealloc_block(t_header* block);

size_t      get_heap_flags1(size_t size);
size_t      get_heap_flags2(size_t size);
size_t      get_heap_size(size_t size);
t_header*   get_last_heap(void);

void        init_block(t_header* block, size_t size);
void        init_heap(t_header* heap, size_t size);

t_header*   search_heap(t_header* block);
t_header*   search_free_block(t_header* heap, size_t size);
t_header*   search_block(void* ptr);

void        *ft_memcpy(void *dst, const void *src, size_t len);

#endif