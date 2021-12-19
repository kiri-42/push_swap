/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:04 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/18 00:42:12 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// paまたはpbをする関数
void	push(t_stack *push_stack, t_stack *pop_stack, char *message)
{
	push_stack->num[push_stack->top + 1] = pop_stack->num[pop_stack->top];
	push_stack->top++;
	pop_stack->top--;
	ft_putendl_fd(message, STDOUT_FILENO);
}
