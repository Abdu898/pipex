/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:15:01 by ashahin           #+#    #+#             */
/*   Updated: 2022/07/02 20:15:01 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parameters
s: The string from which to create the substring.
 start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.
 
Description
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
get_next_line virsion:
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	strlen;

	strlen = ft_strlen(s);
	if ((size_t) start >= strlen)
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		sub_str = (char *)malloc((ft_strlen(&s[start]) + 1) * sizeof(char));
	else
		sub_str = (char *) malloc((len +1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	strlen;

	if (!s)
		return (s);
	strlen = ft_strlen(s);
	if (!s[start] || start >= strlen)
		return (NULL);
	if (len > ft_strlen(&s[start]))
		sub_str = (char *)malloc((ft_strlen(&s[start]) + 1) * sizeof(char));
	else
		sub_str = (char *) malloc((len +1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
*/