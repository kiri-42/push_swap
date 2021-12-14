/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:12:11 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/14 19:14:25 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	finish_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	free(stack_a->num);
	free(stack_b->num);
	return (1);
}
