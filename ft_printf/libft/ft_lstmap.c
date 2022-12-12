/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:49:07 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/29 06:34:36 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), int (*del)(int))
{
	t_list	*new_list;
	t_list	*save;

	if (!lst || !f || !del)
		return (0);
	new_list = ft_lstnew(f(lst->number));
	if (!new_list)
		return (0);
	save = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->number));
		if (!new_list->next)
		{
			ft_lstclear(&save, del);
			return (0);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (save);
}

/*
// t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
// {
// 	t_list	*new;

// 	if (!lst || !(*f))
// 		return (NULL);
// 	new = ft_lstnew((*f)(lst->content));
// 	if (!new)
// 	{
// 		ft_lstclear(&new, del);
// 		return (NULL);
// 	}
// 	new->next = ft_lstmap(lst->next, f, del);
// 	return (new);
// }
*/