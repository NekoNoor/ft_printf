/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_list.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:22:20 by nschat        #+#    #+#                 */
/*   Updated: 2020/01/21 19:32:55 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

t_list	*ft_lstnew(t_data *data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst)
		ft_lstlast(*alst)->next = new;
	else
		*alst = new;
}

void	free_list(t_list **alst)
{
	t_list	*node;
	t_list	*next;

	node = *alst;
	while (node)
	{
		next = node->next;
		free(node->data);
		free(node);
		node = next;
	}
	*alst = NULL;
}
