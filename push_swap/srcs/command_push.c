/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:04 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 15:58:05 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *push_stack, t_stack *pop_stack, char *message)
{
	push_stack->num[push_stack->top + 1] = pop_stack->num[pop_stack->top];
	push_stack->top++;
	pop_stack->top--;
	print_stdout(message);
}
