/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_to_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:17:40 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/09 21:10:04 by tkirihar         ###   ########.fr       */
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
	{
		rotate(stack, "ra");
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rrotate(stack, "rra");
		swap(&stack->num[n1], &stack->num[n2], "sa");
	}
	else if (check_three_sort(stack->num[n2], stack->num[n1], stack->num[n3]))
		swap(&stack->num[n1], &stack->num[n2], "sa");
	else if (check_three_sort(stack->num[n2], stack->num[n3], stack->num[n1]))
	{
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rotate(stack, "ra");
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rrotate(stack, "rra");
	}
	else if (check_three_sort(stack->num[n3], stack->num[n2], stack->num[n1]))
	{
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rotate(stack, "ra");
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rrotate(stack, "rra");
		swap(&stack->num[n1], &stack->num[n2], "sa");
	}
	else if (check_three_sort(stack->num[n1], stack->num[n3], stack->num[n2]))
	{
		rotate(stack, "ra");
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rrotate(stack, "rra");
	}
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

void	A_to_B(size_t sort_size, t_stack *stack_a, t_stack *stack_b)
{
	int		pivot;
	size_t	count_ra;
	size_t	count_pb;
	size_t	i;

	if (sort_size <= 3)
	{
		short_sort_A_to_B(sort_size, stack_a);
		return ;
	}
	if (search_median(stack_a, sort_size, &pivot))
	{
		print_stderr();
		free(stack_a->num);
		free(stack_b->num);
		exit(1);
	}
	count_ra = 0;
	count_pb = 0;
	while (sort_size--)
	{
		if (stack_a->num[stack_a->top] > pivot)
		{
			rotate(stack_a, "ra");
			count_ra++;
		}
		else
		{
			push(stack_b, stack_a, "pb");
			count_pb++;
		}
	}
	i = 1;
	while (i <= count_ra)
	{
		rrotate(stack_a, "rra");
		i++;
	}
	A_to_B(count_ra, stack_a, stack_b);
	B_to_A(count_pb, stack_b, stack_a);
}
