/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 05:08:04 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/12 05:10:06 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	short_sort_A_to_B(size_t sort_size, t_stack *stack_a)
{
	if (sort_size <= 1)
		return ;
	if (sort_size == 2)
	{
		if (stack_a->num[stack_a->top] > stack_a->num[stack_a->top - 1])
			swap(&stack_a->num[stack_a->top], &stack_a->num[stack_a->top - 1],
				"sa");
		return ;
	}
	if (sort_size == 3)
	{
		three_sort_A_to_B(stack_a);
		return ;
	}
}

void	short_sort_B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
{
	if (sort_size <= 1)
	{
		push(stack_a, stack_b, "pa");
		return ;
	}
	if (sort_size == 2)
	{
		if (stack_b->num[stack_b->top] < stack_b->num[stack_b->top - 1])
			swap(&stack_b->num[stack_b->top], &stack_b->num[stack_b->top - 1],
				"sb");
		push(stack_a, stack_b, "pa");
		push(stack_a, stack_b, "pa");
		return ;
	}
	if (sort_size == 3)
	{
		three_sort_B_to_A(stack_b, stack_a);
		return ;
	}
}
