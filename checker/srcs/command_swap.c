#include "../includes/checker.h"

void	swap(int *n1, int *n2, char *message)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
	if (ft_strncmp(message, "ss", 2))
		print_stdout(message);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap(&stack_a->num[stack_a->top], &stack_a->num[stack_a->top - 1], "ss");
	swap(&stack_b->num[stack_b->top], &stack_b->num[stack_b->top - 1], "ss");
	print_stdout("ss");
}
