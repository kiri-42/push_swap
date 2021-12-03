#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	size_t	i;

	if (check_arg(ac, av))
		return (1);
	if (init_stack(&stack_a, &stack_b, ac, av))
		return (1);
	i = 0;
	if (sort(ac - 1, &stack_a, &stack_b))
		return (0);
	while (i < ac - 1)
	{
		printf("%d|", stack_a.num[i]);
		i++;
	}
	return (0);
}
