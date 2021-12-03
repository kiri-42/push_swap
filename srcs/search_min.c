#include "../includes/push_swap.h"

ssize_t	search_min(t_stack *stack)
{
	ssize_t	min;
	ssize_t	i;

	min = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->num[i] < stack->num[min])
			min = i;
		i++;
	}
	return (min);
}
