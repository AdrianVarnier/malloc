#include "malloc.h"

void    ft_print_addr(size_t x)
{
    char base[16] = "0123456789ABCDEF";
    if (x >= 16)
        ft_print_addr(x / 16);
    write(1, &base[x % 16], 1);
}

void    ft_print_number(unsigned long long x)
{
    char base[16] = "0123456789";
    if (x >= 10)
        ft_print_number(x / 10);
    write(1, &base[x % 10], 1);
}