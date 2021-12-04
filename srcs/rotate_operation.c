#include "../includes/push_swap.h"

void	rotate(t_stack *stack, char *message)
{
	int		tmp;
	size_t	i;

	tmp = stack->num[stack->top];
	i = 0;
	while (stack->top - i != 0)
	{
		stack->num[stack->top - i] = stack->num[stack->top - i - 1];
		i++;
	}
	stack->num[0] = tmp;
	print_stdout(message);
}

void	rrotate(t_stack *stack, char *message)
{
	int		tmp;
	size_t	i;

	tmp = stack->num[0];
	i = 0;
	while (i != stack->top)
	{
		stack->num[i] = stack->num[i + 1];
		i++;
	}
	stack->num[stack->top] = tmp;
	print_stdout(message);
}
