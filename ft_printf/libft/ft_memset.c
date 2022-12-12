/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:47:58 by ashahin           #+#    #+#             */
/*   Updated: 2022/07/07 21:47:58 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
copies the character c (an unsigned char) to the first n characters 
of the string pointed to, by the argument str.
*/
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*temb_str;
	size_t	i;

	if (!str)
		return (str);
	i = 0;
	temb_str = (char *)str;
	while (i < n)
	{
		temb_str[i] = c;
		i++;
	}
	return (str);
}
