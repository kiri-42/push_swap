/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:01:41 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 16:01:42 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	read_command(char **command)
{
	*command = get_next_line(STDIN_FILENO);
	if (*command == NULL)
		return (1);
	return (0);
}

static int	run_command(char *command, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(command, "sa\n", 3))
		swap(&stack_a->num[stack_a->top], &stack_a->num[stack_a->top - 1]);
	else if (!ft_strncmp(command, "sb\n", 3))
		swap(&stack_b->num[stack_b->top], &stack_b->num[stack_b->top - 1]);
	else if (!ft_strncmp(command, "ss\n", 3))
		swap_ab(stack_a, stack_b);
	else if (!ft_strncmp(command, "pa\n", 3))
		push(stack_a, stack_b);
	else if (!ft_strncmp(command, "pb\n", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(command, "ra\n", 3))
		rotate(stack_a);
	else if (!ft_strncmp(command, "rb\n", 3))
		rotate(stack_b);
	else if (!ft_strncmp(command, "rr\n", 3))
		rotate_ab(stack_a, stack_b);
	else if (!ft_strncmp(command, "rra\n", 3))
		rrotate(stack_a);
	else if (!ft_strncmp(command, "rrb\n", 3))
		rrotate(stack_b);
	else if (!ft_strncmp(command, "rrr\n", 3))
		rrotate_ab(stack_a, stack_b);
	else
		return (1);
	return (0);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*command;

	command = NULL;
	while (!read_command(&command))
	{
		run_command(command, stack_a, stack_b);
		free(command);
	}
}
