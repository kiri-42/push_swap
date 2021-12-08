/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:01:53 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 16:01:54 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	push(t_stack *push_stack, t_stack *pop_stack)
{
	push_stack->num[push_stack->top + 1] = pop_stack->num[pop_stack->top];
	push_stack->top++;
	pop_stack->top--;
}
