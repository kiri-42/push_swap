/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:12:11 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/18 00:57:57 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// エラーの際に正常に終了させる関数
int	finish_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	free(stack_a->num);
	free(stack_b->num);
	exit(1);
}
