#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (len-- > 0)
		p[i++] = (unsigned char)c;
	return (s);
}
