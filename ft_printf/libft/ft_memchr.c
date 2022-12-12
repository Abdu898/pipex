/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:58:44 by ashahin           #+#    #+#             */
/*   Updated: 2022/06/22 17:58:44 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Locate character in block of memory
Searches within the first num bytes of the block of memory pointed by ptr for the
 first occurrence of value (interpreted as an unsigned char),
  and returns a pointer to it.

Both value and each of the bytes checked on the the ptr array are
 interpreted as unsigned char for the comparison.
 num
Number of bytes to be analyzed.
size_t is an unsigned integral type.
*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temb_str;
	size_t	i;

	temb_str = (char *) s;
	i = 0;
	while (i < n)
	{
		if (*(temb_str + i) == (char) c)
		{
			return (temb_str + i);
		}
		i++;
	}
	return (0);
}
