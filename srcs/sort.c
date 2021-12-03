#include "../includes/push_swap.h"

static int	short_sort(int sort_size, t_stack *stack_a)
{
	if (sort_size == 1)
		;
	else if (sort_size == 2)
	{
		if (stack_a->num[stack_a->top] > stack_a->num[stack_a->top - 1])
			swap(&stack_a->num[stack_a->top], &stack_a->num[stack_a->top - 1], \
			"sa");
	}
	else
	{
		three_sort(stack_a);
	}
	return (0);
}

static int	medium_sort(int sort_size, t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	min;

	while (stack_a->top != 2)
	{
		min = search_min(stack_a);
		while (min != stack_a->top)
		{
			rotate(stack_a);
			min++;
		}
		push(stack_b, stack_a, "pb");
	}
	three_sort(stack_a);
	while (stack_b->top != -1)
	{
		push(stack_a, stack_b, "pa");
	}
	return (0);
}

static int	long_sort(int sort_size, t_stack *stack_a, t_stack *stack_b)
{
	int	median;
	int	i;

	median = search_median(stack_a);
	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->num[stack_a->top] <= median)
			push();
		rotate();
		i++;
	}

}

int	sort(int sort_size, t_stack *stack_a, t_stack *stack_b)
{
	if (sort_size <= 3)
		short_sort(sort_size, stack_a);
	else if (sort_size <= 6)
		medium_sort(sort_size, stack_a, stack_b);
	else
		long_sort(sort_size, stack_a, stack_b);
	return (0);
}
