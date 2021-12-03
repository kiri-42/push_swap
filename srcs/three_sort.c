#include "../includes/push_swap.h"

static int	check_sort(int small, int medium, int large)
{
	return (small < medium && medium < large);
}

int	three_sort(t_stack *stack)
{
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = stack->top;
	n2 = stack->top - 1;
	n3 = stack->top - 2;
	if (check_sort(stack->num[n3], stack->num[n1], stack->num[n2]))
		rrotate(stack);
	else if (check_sort(stack->num[n2], stack->num[n1], stack->num[n3]))
		swap(&stack->num[n1], &stack->num[n2], "sa");
	else if (check_sort(stack->num[n2], stack->num[n3], stack->num[n1]))
		rotate(stack);
	else if (check_sort(stack->num[n3], stack->num[n2], stack->num[n1]))
	{
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rrotate(stack);
	}
	else if (check_sort(stack->num[n1], stack->num[n3], stack->num[n2]))
	{
		swap(&stack->num[n1], &stack->num[n2], "sa");
		rotate(stack);
	}
	return (0);
}
