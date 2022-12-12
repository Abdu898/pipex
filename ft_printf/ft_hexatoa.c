/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:06:54 by ashahin           #+#    #+#             */
/*   Updated: 2022/09/10 04:41:50 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t	hexa_len(unsigned long n)
{
	size_t	n_len;

	if (n == 0)
		return (1);
	n_len = 0;
	while (n != 0)
	{
		n /= 16;
		n_len++;
	}
	return (n_len);
}

void	ft_str_toupper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

int	ft_hexa_dup( unsigned long n)
{
	if ((n % 16) > 9)
		return ((n % 16) + 97 - 10);
	else
		return (n % 16 + '0');
}

char	*ft_hexatoa(unsigned long n)
{
	size_t	len;
	char	*hexastr;

	len = hexa_len(n);
	hexastr = (char *) malloc((len + 1) * sizeof(char));
	if (!hexastr)
		return (0);
	hexastr[len--] = '\0';
	if (n == 0)
	{
		hexastr[0] = '0';
		return (hexastr);
	}
	while (n != 0)
	{
		hexastr[len] = ft_hexa_dup(n);
		n = n / 16;
		len--;
	}
	return (hexastr);
}

/*
http://www.permadi.com/tutorial/numHexToDec/

basically:

Get the right most digit of the hex number, call this digit the currentDigit.
Make a variable, let's call it power. Set the value to 0.
Multiply the current digit with (16^power), store the result.
Increment power by 1.
Set the the currentDigit to the previous digit of the hex number.
Repeat from step 3 until all digits have been multiplied.
Sum the result of step 3 to get the answer number.
*/