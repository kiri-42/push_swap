/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_to_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:18:03 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/12 02:34:29 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	short_sort(t_stack *stack_b, t_stack *stack_a, size_t sort_size)
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

static void	push_B_to_A(t_stack *stack_b, t_stack *stack_a, size_t push_size)
{
	while (push_size > 0)
	{
		push(stack_a, stack_b, "pa");
		push_size--;
	}
}

static bool	check_sort(t_stack *stack_b, t_stack *stack_a, size_t sort_size)
{
	size_t	i;

	if (sort_size <= 3)
	{
		short_sort(stack_b, stack_a, sort_size);
		return (true);
	}
	i = 0;
	while (i < sort_size - 1)
	{
		if (stack_b->num[stack_b->top - i] < \
			stack_b->num[stack_b->top - (i + 1)])
			return (false);
		i++;
	}
	push_B_to_A(stack_b, stack_a, sort_size);
	return (true);
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

// static void	init_count(size_t *count_ra, size_t *count_rb, size_t *count_pa)
// {
// 	*count_ra = 0;
// 	*count_rb = 0;
// 	*count_pa = 0;
// }

// void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
// {
// 	int		pivot1;
// 	int		pivot2;
// 	size_t	count_ra;
// 	size_t	count_rb;
// 	size_t	count_pa;

// 	if (check_sort(stack_b, stack_a, sort_size))
// 		return ;
// 	if (search_pivot(stack_b, sort_size, &pivot1, &pivot2))
// 		exit(finish_error(stack_a, stack_b));
// 	init_count(&count_ra, &count_rb, &count_pa);
// 	while (sort_size > 0)
// 	{
// 		if (stack_b->num[stack_b->top] < pivot1)
// 		{
// 			if (check_less_than_pivot1(stack_b, sort_size, pivot1))
// 				break ;
// 			rotate(stack_b, "rb");
// 			count_rb++;
// 		}
// 		else
// 		{
// 			push(stack_a, stack_b, "pa");
// 			count_pa++;
// 			if (stack_a->num[stack_a->top] < pivot2)
// 			{
// 				rotate(stack_a, "ra");
// 				count_ra++;
// 			}
// 		}
// 		sort_size--;
// 	}
// 	A_to_B(count_pa - count_ra, stack_a, stack_b);
// 	reset_stack(stack_a, stack_b, (ssize_t)count_ra, (ssize_t)count_rb);
// 	A_to_B(count_ra, stack_a, stack_b);
// 	B_to_A(count_rb + sort_size, stack_b, stack_a);
// }

static void	recursive_process(t_stack *stack_a, t_stack *stack_b, size_t sort_size, t_count count)
{
	A_to_B(count.pa - count.ra, stack_a, stack_b);
	reset_stack(stack_a, stack_b, (ssize_t)count.ra, (ssize_t)count.rb);
	A_to_B(count.ra, stack_a, stack_b);
	B_to_A(count.rb + sort_size, stack_b, stack_a);
}

static void	collect_pivot1_or_more(t_stack *stack_a, t_stack *stack_b, int pivot2, t_count *count)
{
	push(stack_a, stack_b, "pa");
	count->pa++;
	if (stack_a->num[stack_a->top] < pivot2)
	{
		rotate(stack_a, "ra");
		count->ra++;
	}
}

static void	collect_less_than_pivot1(t_stack *stack, t_count *count)
{
	rotate(stack, "rb");
	count->rb++;
}

void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
{
	int		pivot1;
	int		pivot2;
	t_count	count;

	if (check_sort(stack_b, stack_a, sort_size))
		return ;
	if (search_pivot(stack_b, sort_size, &pivot1, &pivot2))
		exit(finish_error(stack_a, stack_b));
	init_count(&count);
	while (sort_size > 0)
	{
		if (stack_b->num[stack_b->top] < pivot1)
		{
			if (check_less_than_pivot1(stack_b, sort_size, pivot1))
				break ;
			collect_less_than_pivot1(stack_b, &count);
		}
		else
			collect_pivot1_or_more(stack_a, stack_b, pivot1, &count);
		sort_size--;
	}
	recursive_process(stack_a, stack_b, sort_size, count);
}
