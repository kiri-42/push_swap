/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_to_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:17:40 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/11 22:03:57 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	three_sort_A_to_B(t_stack *stack)
{
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = stack->top;
	n2 = stack->top - 1;
	n3 = stack->top - 2;
	if (check_three_sort(stack->num[n3], stack->num[n1], stack->num[n2]))
		A_to_B_command_case1(stack, n1, n2);
	else if (check_three_sort(stack->num[n2], stack->num[n1], stack->num[n3]))
		A_to_B_command_case2(stack, n1, n2);
	else if (check_three_sort(stack->num[n2], stack->num[n3], stack->num[n1]))
		A_to_B_command_case3(stack, n1, n2);
	else if (check_three_sort(stack->num[n3], stack->num[n2], stack->num[n1]))
		A_to_B_command_case4(stack, n1, n2);
	else if (check_three_sort(stack->num[n1], stack->num[n3], stack->num[n2]))
		A_to_B_command_case5(stack, n1, n2);
}

static void	short_sort_A_to_B(size_t sort_size, t_stack *stack_a)
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

static void	reset_rrotate(t_stack *stack_a, t_stack *stack_b, ssize_t count_ra, ssize_t count_rb)
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

static bool	check_sort(t_stack *stack, size_t sort_size)
{
	size_t	i;

	i = 0;
	while (i < sort_size - 1)
	{
		if (stack->num[stack->top - i] > stack->num[stack->top - (i + 1)])
			return (false);
		i++;
	}
	return (true);
}

static bool	check_pivot2_or_more(t_stack *stack, size_t sort_size, int pivot2)
{
	size_t	i;

	i = 0;
	while (i < sort_size)
	{
		if (stack->num[stack->top - i] < pivot2)
			return (false);
		i++;
	}
	return (true);
}

void	A_to_B(size_t sort_size, t_stack *stack_a, t_stack *stack_b)
{
	int		pivot1;
	int		pivot2;
	size_t	count_ra;
	size_t	count_pb;
	size_t	count_rb;

	if (sort_size <= 3)
	{
		short_sort_A_to_B(sort_size, stack_a);
		return ;
	}
	if (check_sort(stack_a, sort_size))
		return ;
	if (search_pivot(stack_a, sort_size, &pivot1, &pivot2))
		exit(finish_error(stack_a, stack_b));
	count_ra = 0;
	count_pb = 0;
	count_rb = 0;
	while (sort_size > 0)
	{
		if (stack_a->num[stack_a->top] >= pivot2)
		{
			if (check_pivot2_or_more(stack_a, sort_size, pivot2))
				break ;
			rotate(stack_a, "ra");
			count_ra++;
		}
		else
		{
			push(stack_b, stack_a, "pb");
			count_pb++;
			if (stack_b->num[stack_b->top] >= pivot1)
			{
				rotate(stack_b, "rb");
				count_rb++;
			}
		}
		sort_size--;
	}
	reset_rrotate(stack_a, stack_b, (ssize_t)count_ra, (ssize_t)count_rb);
	A_to_B(count_ra + sort_size, stack_a, stack_b);
	B_to_A(count_rb, stack_b, stack_a);
	B_to_A(count_pb - count_rb, stack_b, stack_a);
}
