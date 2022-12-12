/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:57:06 by ashahin           #+#    #+#             */
/*   Updated: 2022/06/29 23:57:06 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strlcpy() function copies up to size - 1 characters 
from the NUL-terminated string src to dst, NUL-terminating the result.

The strlcat() function appends the NUL-terminated string src to the end of dst. 
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
if the size is les or equal to dstlen theen return dstlen + src len
*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	abend_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	abend_len = dst_len + src_len;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (abend_len);
}
