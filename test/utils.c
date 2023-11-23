#include "malloc.h"
#include "test.h"

void print_ko(char* s, int mode)
{
    printf("%s KO\n", s);
    if (mode == 1)
    {
        show_alloc_mem();
        printf("\n");
    }
}

void print_ok(char* s, int mode)
{
    printf("%s OK\n", s);
    if (mode == 1)
    {
        show_alloc_mem();
        printf("\n");
    }
}