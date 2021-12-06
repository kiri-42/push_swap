#include "../includes/push_swap.h"

size_t	search_min(t_stack *stack)
{
	size_t	min;
	size_t	i;

	min = 1;
	i = 2;
	while (i <= stack->top)
	{
		if (stack->num[i] < stack->num[min])
			min = i;
		i++;
	}
	return (min);
}
