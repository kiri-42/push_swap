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
			rotate(stack_a, "ra");
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

static void	A_to_B(size_t sort_size, t_stack *stack_a, t_stack *stack_b)
{
	int		pivot;
	size_t	count_ra;
	size_t	count_pb;
	size_t	i;

	if (sort_size == 1)
		return ;
	pivot = search_median(stack_a);
	count_ra = 0;
	count_pb = 0;
	while (1)
	{
		if (stack_a->num[stack_a->top] > pivot)
		{
			rotate(stack_a, "ra");
			count_ra++;
		}
		else
		{
			push(stack_b, stack_a, "pb");
			count_pb++;
		}
	}
	i = 1;
	while (i <= count_ra)
	{
		rrotate(stack_a, "rra");
		i++;
	}
	A_to_B(count_ra, stack_a, stack_b);
	B_to_A(count_pb, stack_b, stack_a);
}

static void	B_to_A(size_t sort_size, t_stack *stack_b, t_stack *stack_a)
{
	int		pivot;
	size_t	count_rb;
	size_t	count_pa;
	size_t	i;

	if (sort_size == 1)
	{
		push(stack_a, stack_b, "pa");
		return ;
	}
	pivot = search_median(stack_b);
	count_rb = 0;
	count_pa = 0;
	while (1)
	{
		if (stack_b->num[stack_b->top] > pivot)
		{
			rotate(stack_b, "rb");
			count_rb++;
		}
		else
		{
			push(stack_a, stack_b, "pa");
			count_pa++;
		}
	}
	i = 1;
	while (i <= count_rb)
	{
		rrotate(stack_b, "rrb");
		i++;
	}
	A_to_B(count_pa, stack_a, stack_b);
	B_to_A(count_rb, stack_b, stack_a);
}

static int	long_sort(int sort_size, t_stack *stack_a, t_stack *stack_b)
{
	A_to_B((size_t)sort_size, stack_a, stack_b);
	// int	median;
	// int	i;

	// median = search_median(stack_a);

	// i = 0;
	// while (i <= stack_a->top)
	// {
	// 	if (stack_a->num[stack_a->top] <= median)
	// 		push();
	// 	rotate();
	// 	i++;
	// }

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
