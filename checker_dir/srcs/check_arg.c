/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:02:00 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/19 18:48:11 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

// コマンドライン引数が数字かつintの範囲内であることを確認する関数
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
		if (!check_int(av[i]))
			return (false);
		i++;
	}
	return (true);
}

// コマンドライン引数が正しい形式で入力されたか確認する関数
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
