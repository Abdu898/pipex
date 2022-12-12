/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:54:23 by ashahin           #+#    #+#             */
/*   Updated: 2022/07/01 21:54:23 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
The strnstr function locates the first occurrence of the null-terminated
 string \c little in the string \c big, where not more than \c len characters
  are searched. Characters that appear after a \0 character are not searched.
   Since the strnstr function is a FreeBSD specific API,
    it should only be used when portability is not a concern.

	If little is an empty string, big is returned;
	 if little occurs nowhere in big, NULL is returned;
	 otherwise a pointer to the first character of
	  the first occurrence of little is returned.
*/
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenstr1;
	size_t	lenstr2;

	i = 0;
	j = 0;
	lenstr1 = ft_strlen(big);
	lenstr2 = ft_strlen(little);
	if (!lenstr2)
		return ((char *) big);
	while (i < len && i < lenstr1)
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (j == lenstr2)
				return ((char *)(big + i));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
