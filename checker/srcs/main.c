#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	size_t	i;

	if (check_arg(ac, av))
	{
		print_stderr();
		return (1);
	}
	if (init_stack(&stack_a, &stack_b, ac, av))
	{
		print_stderr();
		return (1);
	}
	if (read_stdin())
	{
		// 	print_stderr();
		// 	free(stack_a.num);
		// 	free(stack_b.num);
		// 	return (1);
	}
	// if (sort(ac - 1, &stack_a, &stack_b))
	// {
	// 	print_stderr();
	// 	free(stack_a.num);
	// 	free(stack_b.num);
	// 	return (1);
	// }
	i = 1;
	while (i <= (size_t)ac - 1)
	{
		printf("%d|", stack_a.num[i]);
		i++;
	}
	free(stack_a.num);
	free(stack_b.num);
	return (0);
}
