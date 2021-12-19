/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_to_A_command_case6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:19:25 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/11 22:20:34 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	B_to_A_command_case6(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
}
