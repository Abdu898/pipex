/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:03:34 by ashahin           #+#    #+#             */
/*   Updated: 2022/06/26 14:03:34 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
compares the first n bytes of memory area str1 and memory area str2.
n − This is the number of bytes to be compared.
0	Die verglichenen Zeichen hatten identische Werte
> 0	Die verglichenen Zeichen waren nicht identisch, 
der erste unterschiedliche Wert war bei first größer als bei second
< 0	Die verglichenen Zeichen waren nicht identisch, 
der erste unterschiedliche Wert war bei first kleiner als bei second
*/
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) str1)[i] != ((unsigned char *) str2)[i])
			return (((unsigned char *) str1)[i] - ((unsigned char *) str2)[i]);
		i++;
	}
	return (0);
}
