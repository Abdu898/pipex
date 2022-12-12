/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:27:28 by ashahin           #+#    #+#             */
/*   Updated: 2022/09/10 05:41:10 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t	get_long_len(long n)
{
	int	chars_n;

	chars_n = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		chars_n = 1;
	while (n != 0)
	{
		n /= 10;
		chars_n++;
	}
	return (chars_n);
}

void	ft_put_unsigned_nbr(unsigned int n)
{
	unsigned int	temp;

	temp = n;
	if (temp < 10)
	{
		ft_putchar_fd(temp + '0', 1);
	}
	else
	{
		ft_put_unsigned_nbr(temp / 10);
		ft_put_unsigned_nbr(temp % 10);
	}
}
