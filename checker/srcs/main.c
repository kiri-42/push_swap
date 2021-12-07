#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

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
	sort(&stack_a, &stack_b);
	if (!(check_sort(&stack_a, (size_t)ac - 1) && check_empty(&stack_b)))
	{
		print_stdout("KO");
		free(stack_a.num);
		free(stack_b.num);
		return (1);
	}
	print_stdout("OK");
	free(stack_a.num);
	free(stack_b.num);
	return (0);
}
