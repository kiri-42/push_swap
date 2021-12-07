#include "../includes/checker.h"

bool	check_sort(t_stack *stack, size_t sort_size)
{
	size_t	i;

	i = 1;
	while (i < sort_size)
	{
		if (stack->num[stack->top - i] < stack->num[stack->top - (i + 1)])
			return (false);
		i++;
	}
	return (true);
}
