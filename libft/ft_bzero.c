#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)s;
	while (len-- > 0)
		p[i++] = '\0';
	return ;
}
