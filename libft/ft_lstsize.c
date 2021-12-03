#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*current;

	if (lst == NULL)
		return (0);
	current = lst;
	len = 1;
	while (current->next != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}
