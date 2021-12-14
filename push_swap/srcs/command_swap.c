/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:07 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/14 19:04:28 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *n1, int *n2, char *message)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
	if (ft_strncmp(message, "ss", 2))
		ft_putendl_fd(message, STDOUT_FILENO);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap(&stack_a->num[stack_a->top], &stack_a->num[stack_a->top - 1], "ss");
	swap(&stack_b->num[stack_b->top], &stack_b->num[stack_b->top - 1], "ss");
	ft_putendl_fd("ss", STDOUT_FILENO);
}
