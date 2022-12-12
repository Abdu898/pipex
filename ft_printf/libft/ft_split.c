/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:18:35 by ashahin           #+#    #+#             */
/*   Updated: 2022/07/04 15:18:35 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
		counter++;
		}
		else
			i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	arr = ft_calloc(count_strings((char *)s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	start = 0;
	i = 0;
	while (s[start])
	{
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		if (s[start])
			arr[i] = ft_substr(s, start, end - start);
		i++;
		start = end;
	}
	return (arr);
}
