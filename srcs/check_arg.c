#include "../includes/push_swap.h"

static int	check_digit(int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)ac)
	{
		if (av[i][0] != '-' && !(ft_isdigit(av[i][0])))
		{
			print_stderr("error1");
			return (1);
		}
		j = 1;
		while (av[i][j] != '\0')
		{
			if (!(ft_isdigit(av[i][j++])))
			{
				print_stderr("error2");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	check_arg(int ac, char **av)
{
	if (ac <= 1)
		return (1);
	if (check_digit(ac, av))
		return (1);
	return (0);
}
