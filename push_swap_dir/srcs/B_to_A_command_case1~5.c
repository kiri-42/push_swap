/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_to_A_command_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:32:18 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/09 21:44:00 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	B_to_A_command_case1(t_stack *stack_b, t_stack *stack_a,
		size_t n1, size_t n2)
{
	swap(&stack_b->num[n1], &stack_b->num[n2], "sb");
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
}

void	B_to_A_command_case2(t_stack *stack_b, t_stack *stack_a,
		size_t n1, size_t n2)
{
	rotate(stack_b, "rb");
	swap(&stack_b->num[n1], &stack_b->num[n2], "sb");
	push(stack_a, stack_b, "pa");
	rrotate(stack_b, "rrb");
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
}

void	B_to_A_command_case3(t_stack *stack_b, t_stack *stack_a,
		size_t n1, size_t n2)
{
	push(stack_a, stack_b, "pa");
	swap(&stack_b->num[n1], &stack_b->num[n2], "sb");
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
}

void	B_to_A_command_case4(t_stack *stack_b, t_stack *stack_a,
		size_t n1, size_t n2)
{
	rotate(stack_b, "rb");
	swap(&stack_b->num[n1], &stack_b->num[n2], "sb");
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	rrotate(stack_b, "rrb");
	push(stack_a, stack_b, "pa");
}

void	B_to_A_command_case5(t_stack *stack_b, t_stack *stack_a)
{
	rotate(stack_b, "rb");
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	rrotate(stack_b, "rrb");
	push(stack_a, stack_b, "pa");
}
