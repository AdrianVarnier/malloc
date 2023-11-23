#include "test.h"

static void realloc_null(int mode)
{
    void* ptr[3];
    ptr[0] = malloc(128 -32);
    ptr[1] = realloc(NULL, 128 - 32);
    ptr[2] = realloc(NULL, 0);
    if (!ptr[1] || ptr[2])
        print_ko("realloc_null", mode);
    else
        print_ok("realloc_null", mode);
    free(ptr[0]);
    free(ptr[1]);
    free(ptr[2]);
}

static void realloc_zero(int mode)
{
    void* ptr[2];
    ptr[0] = malloc(128 - 32);
    ptr[1] = realloc(ptr[0], 0);
    if (ptr[1])
        print_ko("realloc_zero", mode);
    else
        print_ok("realloc_zero", mode);
    free(ptr[0]);
    free(ptr[1]);
}

static void realloc_unknow(int mode)
{
    void* ptr[2];
    ptr[0] = malloc(128 - 32);
    ptr[1] = realloc(ptr[0] + 1, 156);
    if (ptr[1])
        print_ko("realloc_unknow", mode);
    else
        print_ok("realloc_unknow", mode);
    free(ptr[0]);
    free(ptr[1]);
}

static void realloc_smaller_tiny(int mode)
{
    void* ptr[2];
    ptr[0] = malloc(128 - 32);
    ptr[1] = realloc(ptr[0], 64);
    if (!ptr[1] || ptr[0] != ptr[1])
        print_ko("realloc_smaller_tiny", mode);
    else
        print_ok("realloc_smaller_tiny", mode);
    free(ptr[0]);
    free(ptr[1]);
}

static void realloc_bigger_tiny10(int mode)
{
    void* ptr[2];
    ptr[0] = malloc(128 - 32);
    ptr[1] = realloc(ptr[0], 256);
    if (!ptr[1] || ptr[0] != ptr[1])
        print_ko("realloc_bigger_tiny10", mode);
    else
        print_ok("realloc_bigger_tiny10", mode);
    free(ptr[0]);
    free(ptr[1]);
}

static void realloc_bigger_tiny11(int mode)
{
    void* ptr[3];
    ptr[0] = malloc(128 - 32);
    ptr[1] = malloc(128 - 32);
    ptr[2] = realloc(ptr[0], 256);
    if (!ptr[2] || ptr[0] == ptr[2])
        print_ko("realloc_bigger_tiny11", mode);
    else
        print_ok("realloc_bigger_tiny11", mode);
    free(ptr[0]);
    free(ptr[1]);
    free(ptr[2]);
}

static void realloc_smaller_small(int mode)
{
    void* ptr[2];
    ptr[0] = malloc(512 - 32);
    ptr[1] = realloc(ptr[0], 256);
    if (!ptr[1] || ptr[0] != ptr[1])
        print_ko("realloc_smaller_small", mode);
    else
        print_ok("realloc_smaller_small", mode);
    free(ptr[0]);
    free(ptr[1]);
}

static void realloc_bigger_small10(int mode)
{
    void* ptr[2];
    ptr[0] = malloc(512 - 32);
    ptr[1] = realloc(ptr[0], 596);
    if (!ptr[1] || ptr[0] != ptr[1])
        print_ko("realloc_bigger_small10", mode);
    else
        print_ok("realloc_bigger_small10", mode);
    free(ptr[0]);
    free(ptr[1]);
}

static void realloc_bigger_small11(int mode)
{
    void* ptr[3];
    ptr[0] = malloc(512 - 32);
    ptr[1] = malloc(512 - 32);
    ptr[2] = realloc(ptr[0], 596);
    if (!ptr[2] || ptr[0] == ptr[2])
        print_ko("realloc_bigger_small11", mode);
    else
        print_ok("realloc_bigger_small11", mode);
    free(ptr[0]);
    free(ptr[1]);
    free(ptr[2]);
}

static void realloc_smaller_large(int mode)
{
    void* ptr[2];
    ptr[0] = malloc(1024 - 32);
    ptr[1] = realloc(ptr, 24);
    if (!ptr[1] || ptr[0] == ptr[1])
        print_ko("realloc_smaller_large", mode);
    else
        print_ok("realloc_smaller_large", mode);
    free(ptr[0]);
    free(ptr[1]);
}

static void realloc_bigger_large(int mode)
{
    void* ptr[2];
    ptr[0] = malloc(1024 - 32);
    ptr[1] = realloc(ptr, 2048);
    if (!ptr[1] || ptr[0] == ptr[1])
        print_ko("realloc_smaller_large", mode);
    else
        print_ok("realloc_smaller_large", mode);
    free(ptr[0]);
    free(ptr[1]);
}

void test_realloc(int mode)
{
    realloc_null(mode);
    realloc_zero(mode);
    realloc_unknow(mode);
    realloc_smaller_tiny(mode);
    realloc_bigger_tiny10(mode);
    realloc_bigger_tiny11(mode);
    realloc_smaller_small(mode);
    realloc_bigger_small10(mode);
    realloc_bigger_small11(mode);
    realloc_smaller_large(mode);
    realloc_bigger_large(mode);
}