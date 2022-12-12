/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:34:18 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/30 02:12:15 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int number)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

/*
	// if (!number)
	// 	return (NULL);
*/