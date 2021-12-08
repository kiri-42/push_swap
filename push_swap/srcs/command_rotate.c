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
	stack->num[1] = tmp;
	if (ft_strncmp(message, "rr", 2))
		print_stdout(message);
}

void	rrotate(t_stack *stack, char *message)
{
	int		tmp;
	size_t	i;

	tmp = stack->num[1];
	i = 1;
	while (i < (size_t)stack->top)
	{
		stack->num[i] = stack->num[i + 1];
		i++;
	}
	stack->num[stack->top] = tmp;
	if (ft_strncmp(message, "rrr", 3))
		print_stdout(message);
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, "rr");
	rotate(stack_b, "rr");
	print_stdout("rr");
}

void	rrotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, "rrr");
	rotate(stack_b, "rrr");
	print_stdout("rrr");
}
