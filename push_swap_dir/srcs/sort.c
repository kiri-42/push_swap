/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:21 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/18 00:47:24 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sort_sizeが3以下のソートを行う関数
static void	short_sort(int sort_size, t_stack *stack_a)
{
	if (sort_size == 1)
		;
	else if (sort_size == 2)
	{
		if (stack_a->num[stack_a->top] > stack_a->num[stack_a->top - 1])
			swap(&stack_a->num[stack_a->top], &stack_a->num[stack_a->top - 1], \
			"sa");
	}
	else
		three_sort(stack_a);
}

// sort_sizeが4以上6以下のソートを行う関数
static void	medium_sort(t_stack *stack_a, t_stack *stack_b)
{
	size_t	min;

	if (check_sort(stack_a))
		return ;
	while (stack_a->top > 3)
	{
		min = search_min(stack_a);
		while (min != stack_a->top)
		{
			rotate(stack_a, "ra");
			min++;
		}
		push(stack_b, stack_a, "pb");
	}
	three_sort(stack_a);
	while (stack_b->top > 0)
		push(stack_a, stack_b, "pa");
}

// sort_sizeが7以上のソートを行う関数
static void	long_sort(int sort_size, t_stack *stack_a, t_stack *stack_b)
{
	A_to_B((size_t)sort_size, stack_a, stack_b);
}

// sort_sizeに応じてソート処理を分ける関数
void	sort(int sort_size, t_stack *stack_a, t_stack *stack_b)
{
	if (sort_size <= 3)
		short_sort(sort_size, stack_a);
	else if (sort_size <= 6)
		medium_sort(stack_a, stack_b);
	else
		long_sort(sort_size, stack_a, stack_b);
}
