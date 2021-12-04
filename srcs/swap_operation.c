#include "../includes/push_swap.h"

void	swap(int *n1, int *n2, char *message)
{
	int	tmp;

	// tmp = stack->num[stack->top];
	// stack->num[stack->top] = stack->num[stack->top - 1];
	// stack->num[stack->top - 1] = tmp;
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
	print_stdout(message);
}
