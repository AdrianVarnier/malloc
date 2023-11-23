#include "malloc.h"
#include "test.h"

static int malloc_zero(int mode)
{
    void* ptr = malloc(0);
    if (ptr)
    {
        print_ko("malloc_zero", mode);
        free(ptr);
        return (1);
    }
    print_ok("malloc_zero", mode);
    return (0);
} 

static int malloc_tiny(int mode)
{
    void* ptr = malloc(128 - 32);
    if (!ptr)
    {
        print_ko("malloc_tiny", mode);
        return (1);
    }
    print_ok("malloc_tiny", mode);
    free(ptr);
    return (0);
} 

static int malloc_small(int mode)
{
    void* ptr = malloc(512 - 32);
    if (!ptr)
    {
        print_ko("malloc_small", mode);
        return (1);
    }
    print_ok("malloc_small", mode);
    free(ptr);
    return (0);
} 

static int malloc_large(int mode)
{
    void* ptr = malloc(1024 - 32);
    if (!ptr)
    {
        print_ko("malloc_large", mode);
        return (1);
    }
    print_ok("malloc_large", mode);
    free(ptr);
    return (0);
} 

static void malloc_multiple_tiny(int mode)
{
    void *ptr[200];
    for (size_t i = 0; i < 200; i++)
    {
        ptr[i] = malloc(128 - 32);
        if (!ptr[i])
        {
            print_ko("malloc_multiple_tiny", mode);
            for (; i > -1; i--)
                free(ptr[i]);
            return ;
        }
    }
    print_ok("malloc_multiple_tiny", mode);
    for (size_t i = 0; i < 200; i++)
        free(ptr[i]);
}

static void malloc_multiple_small(int mode)
{
    void *ptr[200];
    for (size_t i = 0; i < 200; i++)
    {
        ptr[i] = malloc(512 - 32);
        if (!ptr[i])
        {
            print_ko("malloc_multiple_small", mode);
            for (; i > -1; i--)
                free(ptr[i]);
            return ;
        }
    }
    print_ok("malloc_multiple_small", mode);
    for (size_t i = 0; i < 200; i++)
        free(ptr[i]);
}

static void malloc_multiple_large(int mode)
{
    void *ptr[200];
    for (size_t i = 0; i < 200; i++)
    {
        ptr[i] = malloc(1024 - 32);
        if (!ptr[i])
        {
            print_ko("malloc_multiple_large", mode);
            for (; i > -1; i--)
                free(ptr[i]);
            return ;
        }
    }
    print_ok("malloc_multiple_large", mode);
    for (size_t i = 0; i < 200; i++)
        free(ptr[i]);
}

void test_malloc(int mode)
{
    if (mode == -1)
        return ;
    malloc_zero(mode);
    malloc_tiny(mode);
    malloc_multiple_tiny(mode);
    malloc_small(mode);
    malloc_multiple_small(mode);
    malloc_large(mode);
    malloc_multiple_large(mode);
    malloc_multiple(mode);
}