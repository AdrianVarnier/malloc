#include "malloc.h"
#include <stdio.h>

static void print_ko(char* s, int mode)
{
    printf("%s KO\n", s);
    if (mode == 1)
    {
        show_alloc_mem();
        printf("\n");
    }
}

static void print_ok(char* s, int mode)
{
    printf("%s OK\n", s);
    if (mode == 1)
    {
        show_alloc_mem();
        printf("\n");
    }
}

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
    void *ptr[1000];
    for (size_t i = 0; i < 1000; i++)
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
    for (size_t i = 0; i < 1000; i++)
    {
        free(ptr[i]);
    }
}

int main()
{
    int mode = 0;
    malloc_multiple_tiny(mode);
    return (0);
}