/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:49:07 by ashahin           #+#    #+#             */
/*   Updated: 2022/07/02 15:49:07 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Allocates memory for an array of num objects of size and initializes
 all bytes in the allocated storage to zero.
If allocation succeeds, returns a pointer to the lowest (first) byte
 in the allocated memory block that is suitably aligned for any object type.
If size is zero, the behavior is implementation defined
 (null pointer may be returned, or some non-null pointer may be returned
  that may not be used to access storage)
  Parameters
nel	-	number of objects
elsize-	size of each object
*/
#include "libft.h"

void	*ft_calloc(size_t nel, size_t elsize)
{
	void	*p;

	p = malloc(nel * elsize);
	if (!p)
		return (NULL);
	ft_bzero(p, nel * elsize);
	return (p);
}

/*
	int		prod;
	
	if (prod / nel != elsize)
		return (NULL);
*/