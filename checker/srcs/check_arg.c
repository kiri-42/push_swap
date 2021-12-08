/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:02:00 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 16:02:01 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	check_digit(int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)ac)
	{
		if (av[i][0] != '-' && !(ft_isdigit(av[i][0])))
			return (1);
		j = 1;
		while (av[i][j] != '\0')
		{
			if (!(ft_isdigit(av[i][j++])))
				return (1);
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
