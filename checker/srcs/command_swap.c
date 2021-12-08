/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:01:49 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 16:01:50 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap(int *n1, int *n2)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap(&stack_a->num[stack_a->top], &stack_a->num[stack_a->top - 1]);
	swap(&stack_b->num[stack_b->top], &stack_b->num[stack_b->top - 1]);
}
