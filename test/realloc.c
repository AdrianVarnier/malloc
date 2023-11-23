#include "test.h"

static void realloc_null(int mode)
{
    void* ptr[3];
    ptr[0] = malloc(128 -32);
    show_alloc_mem();
    ptr[1] = realloc(NULL, 128 - 32);
    show_alloc_mem();
    ptr[2] = realloc(NULL, 0);
    show_alloc_mem();
    free(ptr[0]);
    free(ptr[1]);
}

static void realloc_unknow(int mode)
{
    void* ptr = malloc(128 -32);
    show_alloc_mem();
    realloc(ptr + 1, 156);
    show_alloc_mem();
    free(ptr);
}

static void realloc_zero(int mode)
{
    void* ptr = malloc(128 -32);
    show_alloc_mem();
    realloc(ptr, 0);
    show_alloc_mem();
}

static void realloc_smaller_tiny(int mode)
{
    void* ptr = malloc(128 -32);
    show_alloc_mem();
    realloc(ptr, 64);
    show_alloc_mem();
    free(ptr);
}

static void realloc_bigger_tiny(int mode)
{
    void* ptr = malloc(128 -32);
    show_alloc_mem();
    realloc(ptr, 256);
    show_alloc_mem();
    free(ptr);
}

static void realloc_smaller_small(int mode)
{
    void* ptr = malloc(512 - 32);
    show_alloc_mem();
    realloc(ptr, 256);
    show_alloc_mem();
    free(ptr);
}

static void realloc_bigger_small(int mode)
{
    void* ptr = malloc(512 - 32);
    show_alloc_mem();
    realloc(ptr, 592);
    show_alloc_mem();
    free(ptr);
}

static void realloc_smaller_large(int mode)
{
    void* ptr = malloc(1024 - 32);
    show_alloc_mem();
    realloc(ptr, 24);
    show_alloc_mem();
    free(ptr);
}

static void realloc_bigger_large(int mode)
{
    void* ptr = malloc(1024 - 32);
    show_alloc_mem();
    realloc(ptr, 2048);
    show_alloc_mem();
    free(ptr);
}