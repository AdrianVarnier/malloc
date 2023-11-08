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

// flags
#define TINY (1 << 0)
#define SMALL (1 << 1)
#define LARGE (1 << 2)

#define FREE (1 << 4)

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
void*   ft_malloc(size_t size);

// utils
t_header*   alloc_heap(size_t size);
t_header*   search_block(t_header* heap, size_t size);

#endif