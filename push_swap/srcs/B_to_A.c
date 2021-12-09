/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_to_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:18:03 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/09 22:42:04 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	three_sort_B_to_A(t_stack *stack_b, t_stack *stack_a)
{
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = stack_b->top;
	n2 = stack_b->top - 1;
	n3 = stack_b->top - 2;
	if (check_three_sort(stack_b->num[n3], stack_b->num[n1], stack_b->num[n2]))
		B_to_A_command_case1(stack_b, stack_a, n1, n2);
	else if (check_three_sort(stack_b->num[n2], stack_b->num[n1],
			stack_b->num[n3]))
		B_to_A_command_case2(stack_b, stack_a, n1, n2);
	else if (check_three_sort(stack_b->num[n2], stack_b->num[n3],
			stack_b->num[n1]))
		B_to_A_command_case3(stack_b, stack_a, n1, n2);
	else if (check_three_sort(stack_b->num[n1], stack_b->num[n2],
			stack_b->num[n3]))
		B_to_A_command_case4(stack_b, stack_a, n1, n2);
	else if (check_three_sort(stack_b->num[n1], stack_b->num[n3],
			stack_b->num[n2]))
		B_to_A_command_case5(stack_b, stack_a);
	else if (check_three_sort(stack_b->num[n3], stack_b->num[n2],
			stack_b->num[n1]))
	{
		push(stack_a, stack_b, "pa");
		push(stack_a, stack_b, "pa");
		push(stack_a, stack_b, "pa");
	}
}

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

static void	reset_rrotate(t_stack *stack, size_t count_rb)
{
	size_t	i;

	i = 1;
	while (i <= count_rb)
	{
		rrotate(stack, "rrb");
		i++;
	}
}

void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
{
	int		pivot;
	size_t	count_rb;
	size_t	count_pa;

	if (sort_size <= 3)
	{
		short_sort_B_to_A(sort_size, stack_b, stack_a);
		return ;
	}
	if (search_median(stack_b, sort_size, &pivot))
		exit(finish_error(stack_a, stack_b));
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
	reset_rrotate(stack_b, count_rb);
	A_to_B(count_pa, stack_a, stack_b);
	B_to_A(count_rb, stack_b, stack_a);
}
