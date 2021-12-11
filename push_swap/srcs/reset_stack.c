/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:31:19 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/11 22:33:24 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reset_stack(t_stack *stack_a, t_stack *stack_b,
		ssize_t count_ra, ssize_t count_rb)
{
	while (count_ra > 0 && count_rb > 0)
	{
		rrotate_ab(stack_a, stack_b);
		count_ra--;
		count_rb--;
	}
	while (count_ra-- > 0)
		rrotate(stack_a, "rra");
	while (count_rb-- > 0)
		rrotate(stack_b, "rrb");
}
