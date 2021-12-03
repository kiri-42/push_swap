#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	i;
	size_t	j;
	char	*p;

	p = (char *)s;
	i = 0;
	if (find[0] == '\0')
		return ((char *)s);
	while (s[i] != '\0' && slen != 0)
	{
		j = 0;
		while (s[i + j] != '\0' && s[i + j] == find[j])
		{
			if (1 > slen - j)
				return (NULL);
			if (find[j + 1] == '\0')
				return (&p[i]);
			j++;
		}
		i++;
		slen--;
	}
	return (NULL);
}
