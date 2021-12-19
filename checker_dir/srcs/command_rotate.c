/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:01:51 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/18 01:39:11 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

// raまたはrbをする関数
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

// rraまたはrrbをする関数
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

// rrをする関数
void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

// rrrをする関数
void	rrotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
}
