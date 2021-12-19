/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:10 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/18 01:19:46 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 数値の重複があるか確認する関数
static bool	check_dup(int num, int *num_list, size_t list_size)
{
	size_t	i;

	i = 1;
	while (i < list_size)
	{
		if (num == num_list[i])
			return (true);
		i++;
	}
	return (false);
}

// スタックABを初期化する関数
int	init_stack(t_stack *stack_a, t_stack *stack_b, int ac, char **av)
{
	size_t	i;
	size_t	j;
	int		tmp;

	stack_a->num = (int *)malloc(sizeof(int) * ac);
	if (stack_a->num == NULL)
		return (1);
	stack_b->num = (int *)malloc(sizeof(int) * ac);
	if (stack_b->num == NULL)
	{
		free(stack_a->num);
		return (1);
	}
	stack_a->top = ac - 1;
	stack_b->top = 0;
	i = 1;
	j = ac - 1;
	while (i <= (size_t)ac - 1)
	{
		tmp = ft_atoi(av[j--]);
		if (check_dup(tmp, stack_a->num, i))
			return (1);
		stack_a->num[i++] = tmp;
	}
	return (0);
}
