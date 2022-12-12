/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:53:55 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/10 12:27:23 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temb;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}	
	temb = ft_lstlast(*lst);
	temb->next = new;
}
