#include "../includes/checker.h"

void	push(t_stack *push_stack, t_stack *pop_stack)
{
	push_stack->num[push_stack->top + 1] = pop_stack->num[pop_stack->top];
	push_stack->top++;
	pop_stack->top--;
}
