/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:57:23 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/16 13:22:20 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (!check_arg(ac, av))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit (1);
	}
	if (init_stack(&stack_a, &stack_b, ac, av))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit (1);
	}
	sort(ac - 1, &stack_a, &stack_b);
	free(stack_a.num);
	free(stack_b.num);
	exit (0);
}
