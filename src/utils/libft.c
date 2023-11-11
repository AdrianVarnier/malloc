#include "malloc.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	for (size_t i = 0; i < len; i++)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}