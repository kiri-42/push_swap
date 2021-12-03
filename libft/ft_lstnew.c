#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_new;

	list_new = (t_list *)malloc(sizeof(t_list));
	if (list_new == NULL)
		return (NULL);
	list_new->content = content;
	list_new->next = NULL;
	return (list_new);
}
