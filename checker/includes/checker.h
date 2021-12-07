#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include "../libft/libft.h"

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
int		sort(char **command_list);

/* get_next_line */
char	*get_next_line(int fd);

/* get_next_line_utils */
char	*free_and_return(char *free_variable);

/* print_message */
void	print_stderr(void);
void	print_stdout(char *message);

#endif
