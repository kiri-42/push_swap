/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:01:51 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/14 17:27:46 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotate(t_stack *stack)
{
	int		tmp;
	size_t	i;

	tmp = stack->num[stack->top];
	i = 0;
	while (stack->top - i > 0)
	{
		stack->num[stack->top - i] = stack->num[stack->top - i - 1];
		i++;
	}
	stack->num[1] = tmp;
}

void	rrotate(t_stack *stack)
{
	int		tmp;
	size_t	i;

	tmp = stack->num[1];
	i = 1;
	while (i < stack->top)
	{
		stack->num[i] = stack->num[i + 1];
		i++;
	}
	stack->num[stack->top] = tmp;
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rrotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
}
