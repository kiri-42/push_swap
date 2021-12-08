/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:15 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 21:19:57 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_p(int *left, int *right)
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
		swap_p(&(stack_num[i]), &(stack_num[j]));
		i++;
		j--;
	}
	quick_sort(stack_num, left, i - 1);
	quick_sort(stack_num, j + 1, right);
}

int	search_median(t_stack *stack, size_t sort_size, int *median)
{
	int	*stack_copy;

	stack_copy = (int *)malloc(sizeof(int) * sort_size);
	if (stack_copy == NULL)
		return (1);
	ft_memcpy(stack_copy, &stack->num[stack->top - (sort_size - 1)],
		sizeof(int) * sort_size);
	quick_sort(stack_copy, 0, (ssize_t)sort_size - 1);
	*median = stack_copy[sort_size / 2];
	free(stack_copy);
	return (0);
}

// //マイナスになるケースがあるため添字変数にssize_tを使う
// static void	quick_sort(int *stack_num, size_t left, size_t right)
// {
// 	int		pivot;
// 	size_t	i;
// 	size_t	j;

// 	if (left >= right)
// 		return ;
// 	pivot = stack_num[left];
// 	i = 0;
// 	j = right;
// 	while (1)
// 	{
// 		while (stack_num[i] < pivot)
// 			i++;
// 		while (stack_num[j] > pivot)
// 			j--;
// 		if (i >= j)
// 			break ;
// 		swap_p(&(stack_num[i]), &(stack_num[j]));
// 		i++;
// 		j--;
// 	}
// 	quick_sort(stack_num, left, i - 1);
// 	quick_sort(stack_num, j + 1, right);
// }

// int	search_median(t_stack *stack, size_t sort_size, int *median)
// {
// 	int	*stack_copy;

// 	stack_copy = (int *)malloc(sizeof(int) * sort_size + 1);
// 	if (stack_copy == NULL)
// 		return (1);
// 	ft_memcpy(&stack_copy[1], &stack->num[1], sizeof(int) * sort_size);
// 	quick_sort(stack_copy, 1, sort_size);
// 	*median = stack_copy[sort_size / 2];
// 	free(stack_copy);
// 	return (0);
// }

// int	main()
// {
// 	t_stack	stack;

// 	stack.num = (int *)malloc(sizeof(int) * 7);
// 	stack.num[0] = 4;
// 	stack.num[1] = 9;
// 	stack.num[2] = 5;
// 	stack.num[3] = 2;
// 	stack.num[4] = 8;
// 	stack.num[5] = 3;
// 	stack.num[6] = 1;
// 	stack.top = 6;
// 	printf("median:%d\n", search_median(&stack, 7));
// 	free(stack.num);
// }
