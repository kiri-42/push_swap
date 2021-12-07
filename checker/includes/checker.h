#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdbool.h>
# include "../../libft/libft.h"

typedef struct s_stack
{
	int		*num;
	size_t	top;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* check_arg */
int		check_arg(int ac, char **av);

/* init_stack */
int		init_stack(t_stack *stack_a, t_stack *stack_b, int ac, char **av);

/* sort */
void	sort(t_stack *stack_a, t_stack *stack_b);

/* get_next_line */
char	*get_next_line(int fd);

/* get_next_line_utils */
char	*free_and_return(char *free_variable);

/* print_message */
void	print_stderr(void);
void	print_stdout(char *message);

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

/* check_sort */
bool	check_sort(t_stack *stack, size_t sort_size);

/* check_empty */
bool	check_empty(t_stack *stack);

#endif
