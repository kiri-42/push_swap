/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_to_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:18:03 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/11 22:36:39 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	short_sort_B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
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

static bool	check_sort(t_stack *stack, size_t sort_size)
{
	size_t	i;

	i = 0;
	while (i < sort_size - 1)
	{
		if (stack->num[stack->top - i] < stack->num[stack->top - (i + 1)])
			return (false);
		i++;
	}
	return (true);
}

static void	push_B_to_A(t_stack *stack_b, t_stack *stack_a, size_t push_size)
{
	while (push_size > 0)
	{
		push(stack_a, stack_b, "pa");
		push_size--;
	}
}

static bool	check_less_than_pivot1(t_stack *stack, size_t sort_size, int pivot1)
{
	size_t	i;

	i = 0;
	while (i < sort_size)
	{
		if (stack->num[stack->top - i] >= pivot1)
			return (false);
		i++;
	}
	return (true);
}

void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
{
	int		pivot1;
	int		pivot2;
	size_t	count_rb;
	size_t	count_pa;
	size_t	count_ra;

	if (sort_size <= 3)
	{
		short_sort_B_to_A(sort_size, stack_b, stack_a);
		return ;
	}
	if (check_sort(stack_b, sort_size))
	{
		push_B_to_A(stack_b, stack_a, sort_size);
		return ;
	}
	if (search_pivot(stack_b, sort_size, &pivot1, &pivot2))
		exit(finish_error(stack_a, stack_b));
	count_rb = 0;
	count_pa = 0;
	count_ra = 0;
	while (sort_size > 0)
	{
		if (stack_b->num[stack_b->top] < pivot1)
		{
			if (check_less_than_pivot1(stack_b, sort_size, pivot1))
				break ;
			rotate(stack_b, "rb");
			count_rb++;
		}
		else
		{
			push(stack_a, stack_b, "pa");
			count_pa++;
			if (stack_a->num[stack_a->top] < pivot2)
			{
				rotate(stack_a, "ra");
				count_ra++;
			}
		}
		sort_size--;
	}
	A_to_B(count_pa - count_ra, stack_a, stack_b);
	reset_stack(stack_a, stack_b, (ssize_t)count_ra, (ssize_t)count_rb);
	A_to_B(count_ra, stack_a, stack_b);
	B_to_A(count_rb + sort_size, stack_b, stack_a);
}
