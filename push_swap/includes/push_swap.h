/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:28 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 22:57:29 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "../../libft/libft.h"

typedef struct s_stack
{
	int		*num;
	size_t	top;
}	t_stack;

/* check_arg */
bool	check_arg(int ac, char **av);

/* init_stack */
int		init_stack(t_stack *stack_a, t_stack *stack_b, int ac, char **av);

/* sort */
int		sort(int sort_size, t_stack *stack_a, t_stack *stack_b);
void	A_to_B(size_t sort_size, t_stack *stack_a, t_stack *stack_b);
void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a);

/* three_sort */
void	three_sort(t_stack *stack);

/* check_three_sort */
bool	check_three_sort(int small, int medium, int large);

/* search_min */
size_t	search_min(t_stack *stack);

/* A_to_B */
void	A_to_B(size_t sort_size, t_stack *stack_a, t_stack *stack_b);

/* B_to_A */
void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a);

/* print_message */
void	print_stdout(char *message);
void	print_stderr(void);

/* search_median */
int		search_median(t_stack *stack, size_t sort_size, int *median);

/* command_swap */
void	swap(int *n1, int *n2, char *message);
void	swap_ab(t_stack *stack_a, t_stack *stack_b);

/* command_push */
void	push(t_stack *push_stack, t_stack *pop_stack, char *message);

/* command_rotate */
void	rotate(t_stack *stack, char *message);
void	rrotate(t_stack *stack, char *message);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	rrotate_ab(t_stack *stack_a, t_stack *stack_b);

#endif
