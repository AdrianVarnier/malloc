#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <sys/mman.h>

// size
#define TINY_HEAP (4 * getpagesize())
#define SMALL_HEAP (16 * getpagesize())

#define TINY_BLOCK (TINY_HEAP / 128)
#define SMALL_BLOCK (SMALL_HEAP / 128)

#define HEAP_SIZE sizeof(t_heap)
#define BLOCK_SIZE sizeof(t_block)

// heap flags
#define TINY (1 << 0)
#define SMALL (1 << 1)
#define LARGE (1 << 2)

// block flags
#define FREE (1 << 0)

// struct
typedef struct s_heap
{
    size_t          size;
    char            flags;
    struct s_heap*  prev;
    struct s_heap*  next;
}   t_heap;

typedef struct  s_block
{
    size_t          size;
    char            flags;
    struct s_block* prev;
    struct s_block* next;
}   t_block;

// global
extern t_heap*  g_heap;

// lib
void*   ft_malloc(size_t size);

// utils
t_heap* create_heap(size_t size);
void*   search_heap(size_t size);

#endif