/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:58:28 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/17 16:49:56 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "../../libft-1.4.1/libft.h"

typedef struct s_stack
{
	int		*num;
	size_t	top;
}	t_stack;

typedef struct s_count
{
	size_t	ra;
	size_t	rb;
	size_t	pa;
	size_t	pb;
}	t_count;

/* check_arg */

bool	check_arg(int ac, char **av);

/* init_stack */

int		init_stack(t_stack *stack_a, t_stack *stack_b, int ac, char **av);

/* sort */

void	sort(int sort_size, t_stack *stack_a, t_stack *stack_b);

/* three_sort */

void	three_sort(t_stack *stack);
void	three_sort_A_to_B(t_stack *stack);
void	three_sort_B_to_A(t_stack *stack_b, t_stack *stack_a);

/* check_three_sort */

bool	check_three_sort(int small, int medium, int large);

/* search_min */

size_t	search_min(t_stack *stack);

/* A_to_B */

void	A_to_B(size_t sort_size, t_stack *stack_a, t_stack *stack_b);

/* A_to_B_command_case */

void	A_to_B_command_case1(t_stack *stack, size_t n1, size_t n2);
void	A_to_B_command_case2(t_stack *stack, size_t n1, size_t n2);
void	A_to_B_command_case3(t_stack *stack, size_t n1, size_t n2);
void	A_to_B_command_case4(t_stack *stack, size_t n1, size_t n2);
void	A_to_B_command_case5(t_stack *stack, size_t n1, size_t n2);

/* B_to_A */

void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a);

/* B_to_A_command_case */

void	B_to_A_command_case1(t_stack *stack_b, t_stack *stack_a, \
size_t n1, size_t n2);
void	B_to_A_command_case2(t_stack *stack_b, t_stack *stack_a, \
size_t n1, size_t n2);
void	B_to_A_command_case3(t_stack *stack_b, t_stack *stack_a, \
size_t n1, size_t n2);
void	B_to_A_command_case4(t_stack *stack_b, t_stack *stack_a, \
size_t n1, size_t n2);
void	B_to_A_command_case5(t_stack *stack_b, t_stack *stack_a);
void	B_to_A_command_case6(t_stack *stack_b, t_stack *stack_a);

/* short_sort */

void	short_sort_A_to_B(size_t sort_size, t_stack *stack_a);
void	short_sort_B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a);

/* check_sort */

bool	check_sort(t_stack *stack);
bool	check_sort_A_to_B(t_stack *stack, size_t sort_size);
bool	check_sort_B_to_A(t_stack *stack_a, t_stack *stack_b, size_t sort_size);

/* reset_stack */

void	reset_stack(t_stack *stack_a, t_stack *stack_b, \
		ssize_t count_ra, ssize_t count_rb);

/* init_count */

void	init_count(t_count *count);

/* search_median */

int		search_pivot(t_stack *stack, size_t sort_size, \
int *pivot1, int *pivot2);

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

/* finish_error */

int		finish_error(t_stack *stack_a, t_stack *stack_b);

#endif
