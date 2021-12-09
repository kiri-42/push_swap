/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_to_B_command_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:32:22 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/09 21:32:23 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	A_to_B_command_case1(t_stack *stack, size_t n1, size_t n2)
{
	rotate(stack, "ra");
	swap(&stack->num[n1], &stack->num[n2], "sa");
	rrotate(stack, "rra");
	swap(&stack->num[n1], &stack->num[n2], "sa");
}

void	A_to_B_command_case2(t_stack *stack, size_t n1, size_t n2)
{
	swap(&stack->num[n1], &stack->num[n2], "sa");
}

void	A_to_B_command_case3(t_stack *stack, size_t n1, size_t n2)
{
	swap(&stack->num[n1], &stack->num[n2], "sa");
	rotate(stack, "ra");
	swap(&stack->num[n1], &stack->num[n2], "sa");
	rrotate(stack, "rra");
}

void	A_to_B_command_case4(t_stack *stack, size_t n1, size_t n2)
{
	swap(&stack->num[n1], &stack->num[n2], "sa");
	rotate(stack, "ra");
	swap(&stack->num[n1], &stack->num[n2], "sa");
	rrotate(stack, "rra");
	swap(&stack->num[n1], &stack->num[n2], "sa");
}

void	A_to_B_command_case5(t_stack *stack, size_t n1, size_t n2)
{
	rotate(stack, "ra");
	swap(&stack->num[n1], &stack->num[n2], "sa");
	rrotate(stack, "rra");
}
