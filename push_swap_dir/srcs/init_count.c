/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 03:51:02 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/18 01:14:54 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// t_countを初期化する関数
void	init_count(t_count *count)
{
	count->ra = 0;
	count->rb = 0;
	count->pa = 0;
	count->pb = 0;
}
