/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:15 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/18 00:35:57 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 左端と右端の値を入れ替える関数
static void	swap_quick_sort(int *left, int *right)
{
	int	tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

// マイナスになるケースがあるため添字変数にssize_tを使う
static void	quick_sort(int *stack_num, ssize_t left, ssize_t right)
{
	int		pivot;
	ssize_t	i;
	ssize_t	j;

	if (left >= right)
		return ;
	pivot = stack_num[left];
	i = 0;
	j = right;
	while (1)
	{
		while (stack_num[i] < pivot)
			i++;
		while (stack_num[j] > pivot)
			j--;
		if (i >= j)
			break ;
		swap_quick_sort(&(stack_num[i]), &(stack_num[j]));
		i++;
		j--;
	}
	quick_sort(stack_num, left, i - 1);
	quick_sort(stack_num, j + 1, right);
}

// pivot(中央値)を探す関数
int	search_pivot(t_stack *stack, size_t sort_size, int *pivot1, int *pivot2)
{
	int	*stack_copy;

	stack_copy = (int *)malloc(sizeof(int) * sort_size);
	if (stack_copy == NULL)
		return (1);
	ft_memcpy(stack_copy, &stack->num[stack->top - (sort_size - 1)],
		sizeof(int) * sort_size);
	quick_sort(stack_copy, 0, (ssize_t)sort_size - 1);
	*pivot1 = stack_copy[sort_size / 3];
	*pivot2 = stack_copy[sort_size / 3 * 2];
	free(stack_copy);
	return (0);
}
