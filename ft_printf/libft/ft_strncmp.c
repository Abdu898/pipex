/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:24:06 by ashahin           #+#    #+#             */
/*   Updated: 2022/06/22 18:24:06 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
does it return the differnce between the two ascii values or -1, 0 and 1
Compares at most count characters of two possibly null-terminated arrays.
 The comparison is done lexicographically. Characters
 following the null character are not compared.
The sign of the result is the sign of the difference between
 the values of the first pair of characters (both interpreted as unsigned char)
  that differ in the arrays being compared.
The behavior is undefined when access occurs past the end of either array lhs
 or rhs. The behavior is undefined when either lhs or rhs is the null pointer.
*/
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && i <= ft_strlen(str1) && i <= ft_strlen(str2))
	{
		if (((unsigned char *) str1)[i] != ((unsigned char *) str2)[i])
			return (((unsigned char *) str1)[i] - ((unsigned char *) str2)[i]);
		i++;
	}
	return (0);
}
