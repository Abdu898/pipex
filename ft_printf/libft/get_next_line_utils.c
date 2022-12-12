/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:43:34 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/01 03:25:52 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* joining s1 and s2 in a new allocated 'string' and return it */
char	*myft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

/* takes strings s1 and start index and the len of the substracted 
string as parameters and returning a new allocated 'string' which 
substracted from the original string starting from @start and its
length is  @len or the length of the original string 
 (it will choose the smaller of them)*/
char	*myft_substr(char *s, unsigned int start, size_t len)
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

/*
size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
*/

/* takes a string as aparameter 
duplicate this string in allocated memory and return it*/
/*
char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	n;

	n = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (n + 1));
	if (!p)
		return (0);
	p[n] = '\0';
	while (n--)
		p[n] = s[n];
	return (p);
}
*/

/*
Locate last occurrence of character in string
Returns a pointer to the last occurrence of character in the C string str.

The terminating null-character is considered part of the C string.
 Therefore, it can also be located to retrieve a pointer to the end of a string.
 error t + 256????
*/
/*
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (unsigned char) c)
			return ((char *)(s + len));
		len--;
	}
	return (0);
}
*/