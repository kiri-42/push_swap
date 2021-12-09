/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:57:23 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/09 02:59:39 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	size_t	i;

	if (!check_arg(ac, av))
	{
		print_stderr();
		return (1);
	}
	if (init_stack(&stack_a, &stack_b, ac, av))
	{
		print_stderr();
		return (1);
	}
	if (sort(ac - 1, &stack_a, &stack_b))
	{
		print_stderr();
		free(stack_a.num);
		free(stack_b.num);
		return (1);
	}
	i = 1;
	while (i <= (size_t)ac - 1)
	{
		printf("%d|", stack_a.num[i]);
		i++;
	}
	free(stack_a.num);
	free(stack_b.num);
	return (0);
}
