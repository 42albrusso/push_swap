/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_lst_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:35 by albrusso          #+#    #+#             */
/*   Updated: 2023/01/27 14:38:32 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(list) * 4);
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstprint(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (temp != NULL)
	{
		printf("%d ", temp->content);
		temp = temp->next;
	}
	printf("\n");
}
