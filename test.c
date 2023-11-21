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

static void test_free()
{
    void* ptr[11];
    for (size_t i = 0; i < 5; i++)
        ptr[i] = malloc(128 - 32);
    for (size_t i = 5; i < 10; i++)
        ptr[i] = malloc(512 - 32);
    ptr[10] = malloc(1024 - 32);
    free(NULL);
    free(ptr[0] + 1);
    show_alloc_mem();
    for (size_t i = 0; i < 11; i++)
        free(ptr[i]);
    show_alloc_mem();
}

static void realloc_null(int mode)
{
    void* result[2];
    void* ptr[11];
    for (size_t i = 0; i < 5; i++)
        ptr[i] = malloc(16);
    for (size_t i = 5; i < 10; i++)
        ptr[i] = malloc(156);
    result[0] = realloc(NULL, 0);
    result[1] = realloc(NULL, 32);
    if (result[0] != NULL && result[1] == NULL)
        print_ko("realloc_null", mode);
    else
        print_ok("realloc_null", mode);
    for (size_t i = 0; i < 10; i++)
        free(ptr[i]);
    for (size_t i = 0; i < 2; i++)
        free(result[i]);
}

static void realloc_unknow(int mode)
{
    void* result;
    void* ptr[11];
    for (size_t i = 0; i < 5; i++)
        ptr[i] = malloc(16);
    for (size_t i = 5; i < 10; i++)
        ptr[i] = malloc(156);
    result = realloc(ptr[0] + 1, 12);
    if (result != NULL)
        print_ko("realloc_unknow", mode);
    else
        print_ok("realloc_unknow", mode);
    for (size_t i = 0; i < 10; i++)
        free(ptr[i]);
}

static void realloc_zero(int mode)
{
    void* result;
    void* ptr[11];
    for (size_t i = 0; i < 5; i++)
        ptr[i] = malloc(16);
    for (size_t i = 5; i < 10; i++)
        ptr[i] = malloc(156);
    result = realloc(ptr[0], 0);
    if (result != NULL)
        print_ko("realloc_unknow", mode);
    else
        print_ok("realloc_unknow", mode);
    for (size_t i = 0; i < 10; i++)
        free(ptr[i]);
}

static void realloc_smaller(int mode)
{
    void* result[1];
    void* ptr[11];
    for (size_t i = 0; i < 5; i++)
        ptr[i] = malloc(16);
    for (size_t i = 5; i < 10; i++)
        ptr[i] = malloc(200);
    ptr[10] = malloc(1000);
    if (mode)
        show_alloc_mem();
    free(ptr[1]);
    free(ptr[6]);
    result[0] = realloc(ptr[0], 32);
    result[1] = realloc(ptr[2], 32);
    result[2] = realloc(ptr[6], 300);
    result[3] = realloc(ptr[8], 300);
    result[4] = realloc(ptr[10], 2000);

}

int main()
{
    int mode = 1;
    malloc_zero(mode);
    malloc_tiny(mode);
    malloc_small(mode);
    malloc_large(mode);
    malloc_multiple_tiny(0);
    malloc_multiple_small(0);
    malloc_multiple_large(0);
    malloc_multiple(0);
    test_free();
    realloc_null(mode);
    realloc_unknow(mode);
    realloc_zero(mode);
    return (0);
}