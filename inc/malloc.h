#ifndef MALLOC_H
#define MALLOC_H

#include <string.h>

//define

#define TINY_HEAP (4 * getpagesize())
#define SMALL_HEAP (16 * getpagesize())
#define TINY_BLOCK (TINY_HEAP / 128)
#define SMALL_BLOCK (SMALL_HEAP / 128)

//type

typedef enum e_bool {
    FALSE,
    TRUE
}   t_bool;

//struct

typedef struct  s_heap {
    struct s_heap*  prev;
    struct s_heap*  next;
    size_t          size;
    size_t          free_size;
    size_t          block;
}   t_heap;

typedef struct  s_block {
    struct s_block* prev;
    struct s_block* next;
    size_t          size;
    t_bool          free;
}   t_block;

//global

extern t_heap*  heap;

//lib

void*   ft_malloc(size_t size);

#endif