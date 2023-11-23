#include "test.h"

static void free_tiny(void)
{
    void* ptr = malloc(128 - 32);
    show_alloc_mem();
    free(ptr);
    show_alloc_mem();
}

static void free_tiny10(void)
{
    void* ptr[2];
    ptr[0] = malloc(128 - 32);
    ptr[1] = malloc(128 - 32);
    show_alloc_mem();
    free(ptr[1]);
    show_alloc_mem();
    free(ptr[2]);
}

static void free_tiny01(void)
{
    void* ptr[2];
    ptr[0] = malloc(128 - 32);
    ptr[1] = malloc(128 - 32);
    show_alloc_mem();
    free(ptr[2]);
    show_alloc_mem();
    free(ptr[1]);
}

static void free_defragmented_tiny(void)
{
    void* ptr[4];
    ptr[0] = malloc(128 - 32);
    ptr[1] = malloc(128 - 32);
    ptr[2] = malloc(128 - 32);
    ptr[3] = malloc(128 - 32);
    show_alloc_mem();
    free(ptr[1]);
    free(ptr[2]);
    show_alloc_mem();
    free(ptr[0]);
    free(ptr[3]);
}

static void free_small(void)
{
    void* ptr = malloc(512 - 32);
    show_alloc_mem();
    free(ptr);
    show_alloc_mem();
}

static void free_small10(void)
{
    void* ptr[2];
    ptr[0] = malloc(512 - 32);
    ptr[1] = malloc(512 - 32);
    show_alloc_mem();
    free(ptr[1]);
    show_alloc_mem();
    free(ptr[2]);
}

static void free_small01(void)
{
    void* ptr[2];
    ptr[0] = malloc(512 - 32);
    ptr[1] = malloc(512 - 32);
    show_alloc_mem();
    free(ptr[2]);
    show_alloc_mem();
    free(ptr[1]);
}

static void free_defragmented_small(void)
{
    void* ptr[4];
    ptr[0] = malloc(512 - 32);
    ptr[1] = malloc(512 - 32);
    ptr[2] = malloc(512 - 32);
    ptr[3] = malloc(512 - 32);
    show_alloc_mem();
    free(ptr[1]);
    free(ptr[2]);
    show_alloc_mem();
    free(ptr[0]);
    free(ptr[3]);
}

static void free_large(void)
{
    void* ptr = malloc(1024 - 32);
    show_alloc_mem();
    free(ptr);
    show_alloc_mem();
}

static void free_null(void)
{
    void* ptr = malloc(128 - 32);
    show_alloc_mem();
    free(NULL);
    show_alloc_mem();
    free(ptr);
    free(NULL);
    show_alloc_mem();
}

static void free_unknow(void)
{
    void* ptr = malloc(128 - 32);
    show_alloc_mem();
    free(ptr + 1);
    show_alloc_mem();
    free(ptr);
}

void test_free(void)
{
    free_tiny();
    free_tiny10();
    free_tiny01();
    free_defragmented_tiny();
    free_small();
    free_small10();
    free_small01();
    free_defragmented_small();
    free_large();
    free_null();
    free_unknow();
}