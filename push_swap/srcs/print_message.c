#include "../includes/push_swap.h"

void	print_stdout(char *message)
{
	write(STDOUT_FILENO, message, ft_strlen(message));
	write(STDOUT_FILENO, "\n", 1);
}

void	print_stderr(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}
