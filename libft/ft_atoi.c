#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

static int	check_min(const char *nptr)
{
	if (!(ft_strncmp(nptr, "-2147483648", 11)))
		return (-1);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	sign = check_min(&nptr[i]);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-' && sign == 1)
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}
