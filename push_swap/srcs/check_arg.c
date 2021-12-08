/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:02 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 18:48:13 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	check_digit(int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)ac)
	{
		if (av[i][0] != '-' && !(ft_isdigit(av[i][0])))
			return (false);
		j = 1;
		while (av[i][j] != '\0')
		{
			if (!(ft_isdigit(av[i][j++])))
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_arg(int ac, char **av)
{
	if (ac <= 0)
		return (false);
	if (ac == 1)
		exit(0);
	if (!check_digit(ac, av))
		return (false);
	return (true);
}
