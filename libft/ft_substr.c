#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	region;

	if (ft_strlen(s) < start)
	{
		p = (char *)malloc(1);
		if (p == NULL)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	region = ft_strlen(s) - start;
	if (len <= region)
		region = len;
	p = (char *)malloc(region + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (len-- && s[start] != '\0')
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
