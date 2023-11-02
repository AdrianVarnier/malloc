#include "malloc.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char *tiny = ft_malloc(5);
    strcpy(tiny, "abcd");
    printf("%s\n", tiny);
    char *small = ft_malloc(15);
    strcpy(small, "0123456789abcd0123456789");
    printf("%s\n", small);
    return (0);
}