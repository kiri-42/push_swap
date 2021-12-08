/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_to_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:18:03 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 17:20:43 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
{
	int		pivot;
	size_t	count_rb;
	size_t	count_pa;
	size_t	i;

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
	if (search_median(stack_b, sort_size, &pivot))
	{
		print_stderr();
		free(stack_a->num);
		free(stack_b->num);
		exit(1);
	}
	count_rb = 0;
	count_pa = 0;
	while (sort_size--)
	{
		if (stack_b->num[stack_b->top] < pivot)
		{
			rotate(stack_b, "rb");
			count_rb++;
		}
		else
		{
			push(stack_a, stack_b, "pa");
			count_pa++;
		}
	}
	i = 1;
	while (i <= count_rb)
	{
		rrotate(stack_b, "rrb");
		i++;
	}
	A_to_B(count_pa, stack_a, stack_b);
	B_to_A(count_rb, stack_b, stack_a);
}
