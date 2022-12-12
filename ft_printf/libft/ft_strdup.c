/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:29:31 by ashahin           #+#    #+#             */
/*   Updated: 2022/07/02 18:29:31 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
