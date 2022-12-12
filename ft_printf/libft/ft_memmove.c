/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:40:34 by ashahin           #+#    #+#             */
/*   Updated: 2022/06/26 19:40:34 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Move block of memory
Copies the values of num bytes from the location pointed by source
 to the memory block pointed by destination.
 Copying takes place as if an intermediate buffer were used,
  allowing the destination and source to overlap.

The underlying type of the objects pointed by both the source
 and destination pointers are irrelevant for this function;
 The result is a binary copy of the data.

The function does not check for any terminating null character
 in source - it always copies exactly num bytes.

To avoid overflows, the size of the arrays pointed by both 
the destination and source parameters, shall be at least num bytes.
*/
#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t numBytes)
{
	size_t	i;

	if (!to || !from)
		return (0);
	i = 0;
	if ((size_t)(to - from) >= numBytes)
	{
		while (i < numBytes)
		{
			((unsigned char *)to)[i] = ((unsigned char *)from)[i];
			i++;
		}
	}
	if ((size_t)(to - from) < numBytes)
	{
		while (numBytes--)
			((unsigned char *)to)[numBytes] = ((unsigned char *)from)[numBytes];
	}
	return (to);
}
