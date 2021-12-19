/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:06 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/18 00:52:32 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// raまたはrbをする関数
void	rotate(t_stack *stack, char *message)
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
	if (ft_strncmp(message, "rr", 2))
		ft_putendl_fd(message, STDOUT_FILENO);
}

// rraまたはrrbをする関数
void	rrotate(t_stack *stack, char *message)
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
	if (ft_strncmp(message, "rrr", 3))
		ft_putendl_fd(message, STDOUT_FILENO);
}

// rrをする関数
void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, "rr");
	rotate(stack_b, "rr");
	ft_putendl_fd("rr", STDOUT_FILENO);
}

// rrrをする関数
void	rrotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rrotate(stack_a, "rrr");
	rrotate(stack_b, "rrr");
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
