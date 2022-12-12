/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_schr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:11:56 by ashahin           #+#    #+#             */
/*   Updated: 2022/06/22 18:11:56 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Locate first occurrence of character in string
Returns a pointer to the first occurrence of character in the C string str.

The terminating null-character is considered part of the C string.
 Therefore, it can also be located in order to retrieve a 

	The strchr() and strrchr() functions return a pointer to the
	matched character or NULL if the character is not found.  The
	terminating null byte is considered part of the string, so that
	if c is specified as '\0', these functions return a pointer to
	the terminator.
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
