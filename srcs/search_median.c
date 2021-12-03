#include "../includes/push_swap.h"

static void	swap_p(int *left, int *right)
{
	int	tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

static void	quick_sort(int *stack_num, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = stack_num[left];
	i = 0;
	j = right;
	while (1)
	{
		while (stack_num[i] < pivot)
			i++;
		while (stack_num[j] > pivot)
			j--;
		if (i >= j)
			break ;
		swap_p(&(stack_num[i]), &(stack_num[j]));
		i++;
		j--;
	}
	quick_sort(stack_num, left, i - 1);
	quick_sort(stack_num, j + 1, right);
}

int	search_median(t_stack *stack)
{
	int	*stack_copy;
	int	median;

	stack_copy = (int *)malloc(sizeof(int) * (stack->top + 1));
	if (stack_copy == NULL)
		return (1);
	ft_memcpy(stack_copy, stack->num, sizeof(int) * (stack->top + 1));
	quick_sort(stack_copy, 0, (int)stack->top);
	median = stack_copy[(stack->top + 1) / 2];
	free(stack_copy);
	return (median);
}

// int	main()
// {
// 	t_stack	stack;

// 	stack.num = (int *)malloc(sizeof(int) * 6);
// 	stack.num[0] = 3;
// 	stack.num[1] = 6;
// 	stack.num[2] = 4;
// 	stack.num[3] = 1;
// 	stack.num[4] = 2;
// 	stack.num[5] = 5;
// 	stack.top = 5;
// 	printf("median:%d\n", search_median(&stack));
// 	free(stack.num);
// }
