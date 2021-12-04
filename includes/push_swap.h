#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define STACK_A 0
# define STACK_B 1

typedef struct s_stack
{
	int		*num;
	ssize_t	top;
}	t_stack;

/* init_stack */
int		init_stack(t_stack *stack_a, t_stack *stack_b, int ac, char **av);

/* print_message */
void	print_stdout(char *message);
void	print_stderr(char *message);

/* check_arg */
int		check_arg(int ac, char **av);

/* sort */
int		sort(int sort_size, t_stack *stack_a, t_stack *stack_b);

/* three_sort */
int		three_sort(t_stack *stack);

/* swap_operation */
void	swap(int *n1, int *n2, char *message);
void	swap_ab(t_stack *stack_a, t_stack *stack_b);

/* push_operation */
void	push(t_stack *push_stack, t_stack *pop_stack, char *message);

/* rotate_operation */
void	rotate(t_stack *stack, char *message);
void	rrotate(t_stack *stack, char *message);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	rrotate_ab(t_stack *stack_a, t_stack *stack_b);

/* search_median */
int		search_median(t_stack *stack);
// void	quick_sort(int *stack, int left, int right);

/* search_min */
ssize_t	search_min(t_stack *stack);

#endif
