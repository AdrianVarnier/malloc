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
        free(ptr[i]);
}

static void malloc_multiple_small(int mode)
{
    void *ptr[1000];
    for (size_t i = 0; i < 1000; i++)
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
    for (size_t i = 0; i < 1000; i++)
        free(ptr[i]);
}

static void malloc_multiple_large(int mode)
{
    void *ptr[1000];
    for (size_t i = 0; i < 1000; i++)
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
    for (size_t i = 0; i < 1000; i++)
        free(ptr[i]);
}

static void malloc_multiple(int mode)
{
    void *ptr[50];
    for (size_t i = 0; i < 50; i++)
    {
        if (i % 10 == 0 || i % 5 == 0)
            ptr[i] = malloc(1024 - 32);
        else if (i % 2 == 0)
            ptr[i] = malloc(128 - 32);
        else
            ptr[i] = malloc(512 - 32);
        if (!ptr[i])
        {
            print_ko("malloc_multiple", mode);
            for (; i > -1; i--)
                free(ptr[i]);
            return ;
        }
    }
    print_ok("malloc_multiple", mode);
    for (size_t i = 0; i < 50; i++)
        free(ptr[i]);
}

static void free_tiny()
{
}

static void free_tiny10()
{
}

static void free_tiny01()
{
}

static void free_defragmented_tiny()
{
}

static void free_small()
{
}

static void free_small10()
{
}

static void free_small01()
{
}

static void free_defragmented_small()
{
}

static void free_large()
{
}

static void free_null()
{
}

static void free_unknow()
{
}

static void realloc_null(int mode)
{
}

static void realloc_unknow(int mode)
{
}

static void realloc_zero(int mode)
{
}

static void realloc_smaller_tiny(int mode)
{
}

static void realloc_bigger_tiny(int mode)
{
}

static void realloc_smaller_small(int mode)
{
}

static void realloc_bigger_small(int mode)
{
}

static void realloc_smaller_large(int mode)
{
}

static void realloc_bigger_large(int mode)
{
}

int main()
{
    int mode = 1;
    malloc_zero(mode);
    malloc_tiny(mode);
    malloc_small(mode);
    malloc_large(mode);
    malloc_multiple_tiny(mode);
    malloc_multiple_small(mode);
    malloc_multiple_large(mode);
    malloc_multiple(mode);
    return (0);
}