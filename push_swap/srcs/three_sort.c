/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:23 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/12 05:31:25 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort(t_stack *stack)
{
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = stack->top;
	n2 = stack->top - 1;
	n3 = stack->top - 2;
	if (check_three_sort(stack->num[n3], stack->num[n1], stack->num[n2]))
		rrotate(stack, "rra");
	else if (check_three_sort(stack->num[n2], stack->num[n1], stack->num[n3]))
		swap(&stack->num[n1], &stack->num[n2], "sa");
	else if (check_three_sort(stack->num[n2], stack->num[n3], stack->num[n1]))
		rotate(stack, "ra");
	else if (check_three_sort(stack->num[n3], stack->num[n2], stack->num[n1]))
	{
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rrotate(stack, "rra");
	}
	else if (check_three_sort(stack->num[n1], stack->num[n3], stack->num[n2]))
	{
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rotate(stack, "ra");
	}
}

void	three_sort_A_to_B(t_stack *stack)
{
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = stack->top;
	n2 = stack->top - 1;
	n3 = stack->top - 2;
	if (check_three_sort(stack->num[n3], stack->num[n1], stack->num[n2]))
		A_to_B_command_case1(stack, n1, n2);
	else if (check_three_sort(stack->num[n2], stack->num[n1], stack->num[n3]))
		A_to_B_command_case2(stack, n1, n2);
	else if (check_three_sort(stack->num[n2], stack->num[n3], stack->num[n1]))
		A_to_B_command_case3(stack, n1, n2);
	else if (check_three_sort(stack->num[n3], stack->num[n2], stack->num[n1]))
		A_to_B_command_case4(stack, n1, n2);
	else if (check_three_sort(stack->num[n1], stack->num[n3], stack->num[n2]))
		A_to_B_command_case5(stack, n1, n2);
}

void	three_sort_B_to_A(t_stack *stack_b, t_stack *stack_a)
{
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = stack_b->top;
	n2 = stack_b->top - 1;
	n3 = stack_b->top - 2;
	if (check_three_sort(stack_b->num[n3], stack_b->num[n1], stack_b->num[n2]))
		B_to_A_command_case1(stack_b, stack_a, n1, n2);
	else if (check_three_sort(stack_b->num[n2], stack_b->num[n1],
			stack_b->num[n3]))
		B_to_A_command_case2(stack_b, stack_a, n1, n2);
	else if (check_three_sort(stack_b->num[n2], stack_b->num[n3],
			stack_b->num[n1]))
		B_to_A_command_case3(stack_b, stack_a, n1, n2);
	else if (check_three_sort(stack_b->num[n1], stack_b->num[n2],
			stack_b->num[n3]))
		B_to_A_command_case4(stack_b, stack_a, n1, n2);
	else if (check_three_sort(stack_b->num[n1], stack_b->num[n3],
			stack_b->num[n2]))
		B_to_A_command_case5(stack_b, stack_a);
	else if (check_three_sort(stack_b->num[n3], stack_b->num[n2],
			stack_b->num[n1]))
		B_to_A_command_case6(stack_b, stack_a);
}
