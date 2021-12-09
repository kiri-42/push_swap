/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_to_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:17:40 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/09 18:25:13 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort2(t_stack *stack)
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

// void	medium_sort2(t_stack *stack_a, t_stack *stack_b)
// {
// 	size_t	min;
// 	size_t	count_pb;
// 	size_t	count_ra;

// 	count_pb = 0;
// 	while (stack_a->top > 3)
// 	{
// 		count_ra = 0;
// 		min = search_min(stack_a);
// 		while (min != stack_a->top)
// 		{
// 			rotate(stack_a, "ra");
// 			min++;
// 			count_ra++;
// 		}
// 		push(stack_b, stack_a, "pb");
// 		count_pb++;
// 		while (count_ra > 0)
// 		{
// 			rrotate(stack_a, "rra");
// 			count_ra--;
// 		}
// 	}
// 	three_sort2(stack_a);
// 	while (count_pb > 0)
// 	{
// 		push(stack_a, stack_b, "pa");
// 		count_pb--;
// 	}
// }

void	short_sort2(size_t sort_size, t_stack *stack_a)
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
		three_sort2(stack_a);
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
		short_sort2(sort_size, stack_a);
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
