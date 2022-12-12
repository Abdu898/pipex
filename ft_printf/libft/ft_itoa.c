/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:30:52 by ashahin           #+#    #+#             */
/*   Updated: 2022/07/06 20:30:52 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
converts integer to string
*/
#include "libft.h"

static int	count_digits(int n)
{
	int	chars_n;

	if (n == 0)
		return (1);
	chars_n = 0;
	if (n < 0)
		chars_n = 1;
	while (n != 0)
	{
		n /= 10;
		chars_n++;
	}
	return (chars_n);
}

static int	digit_dup( int n)
{
	if (n < 0)
		return (n % 10 * (-1) + '0');
	else
		return (n % 10 + '0');
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = count_digits(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n != 0)
	{
		str[len] = digit_dup(n);
		n = n / 10;
		len--;
	}
	if (len == 0)
		str[len] = '-';
	return (str);
}
