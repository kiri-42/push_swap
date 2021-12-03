#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	size_t			len;

	char_s = (unsigned char *)s;
	len = 0;
	while (len < n)
	{
		if (char_s[len] == c)
			return ((void *)s + len);
		else
			len++;
	}
	return (NULL);
}
