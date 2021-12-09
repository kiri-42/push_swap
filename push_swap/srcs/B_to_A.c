/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_to_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:18:03 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/09 21:46:38 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort3(t_stack *stack_b, t_stack *stack_a)
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

void	short_sort3(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
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
		three_sort3(stack_b, stack_a);
	}
}

void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
{
	int		pivot;
	size_t	count_rb;
	size_t	count_pa;
	size_t	i;

	if (sort_size <= 3)
	{
		short_sort3(sort_size, stack_b, stack_a);
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
