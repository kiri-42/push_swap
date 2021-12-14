/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:01:43 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/14 20:38:25 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (!check_arg(ac, av))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	if (init_stack(&stack_a, &stack_b, ac, av))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	sort(&stack_a, &stack_b);
	if (!(check_sort(&stack_a, (size_t)ac - 1) && check_empty(&stack_b)))
	{
		ft_putendl_fd("KO", STDOUT_FILENO);
		free(stack_a.num);
		free(stack_b.num);
		return (1);
	}
	ft_putendl_fd("OK", STDOUT_FILENO);
	free(stack_a.num);
	free(stack_b.num);
	return (0);
}
