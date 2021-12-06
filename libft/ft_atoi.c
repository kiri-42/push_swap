#include "libft.h"

static int	ft_isspace(char a)
{
	if (a == '\t' || a == '\n' || a == '\v'
		|| a == ' ' || a == '\r' || a == '\f' )
		return (1);
	return (0);
}

static long	process_flow(int sign)
{
	if (sign == -1)
	{
		return (LONG_MIN);
	}
	return (LONG_MAX);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long		num;
	int			sign;

	num = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((num * 10 + (str[i] - '0')) / 10 != num)
			return ((int)process_flow(sign));
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(num * sign));
}
