#include "../includes/checker.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str[len] != '\0')
// 		len++;
// 	return (len);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*p;
// 	size_t	i;
// 	size_t	j;

// 	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (p == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		p[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 	{
// 		p[i++] = s2[j++];
// 	}
// 	p[i] = '\0';
// 	return (p);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != (char)c && s[i] != '\0')
// 		i++;
// 	if (s[i] == (char)c)
// 		return ((char *)&s[i]);
// 	else
// 		return (NULL);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*p;
// 	size_t	i;
// 	size_t	region;

// 	if (ft_strlen(s) < start)
// 	{
// 		p = (char *)malloc(1);
// 		if (p == NULL)
// 			return (NULL);
// 		p[0] = '\0';
// 		return (p);
// 	}
// 	region = ft_strlen(s) - start;
// 	if (len <= region)
// 		region = len;
// 	p = (char *)malloc(region + 1);
// 	if (p == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (len-- && s[start] != '\0')
// 		p[i++] = s[start++];
// 	p[i] = '\0';
// 	return (p);
// }

char	*free_and_return(char *free_variable)
{
	free(free_variable);
	return (NULL);
}
