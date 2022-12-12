/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:11:14 by ashahin           #+#    #+#             */
/*   Updated: 2022/06/26 18:11:14 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t	n)
{
	unsigned char	*temb_src;
	unsigned char	*temb_dst;

	temb_src = (unsigned char *) src;
	temb_dst = (unsigned char *) dst;
	if (!dst && !src)
		return (dst);
	while (n-- > 0)
	{
		*(temb_dst + n) = *(temb_src + n);
	}
	return ((void *) dst);
}
