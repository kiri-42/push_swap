/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_three_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:55:15 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 22:57:20 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	check_three_sort(int small, int medium, int large)
{
	return (small < medium && medium < large);
}
