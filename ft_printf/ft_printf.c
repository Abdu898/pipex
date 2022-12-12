/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:39:21 by ashahin           #+#    #+#             */
/*   Updated: 2022/07/29 22:39:21 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	conv_cases(va_list list, const char c)
{
	int	len;

	len = 0;
	if (c == 's')
		len += case_string(list);
	else if (c == 'p')
		len += case_pointer(list);
	else if (c == 'c')
		len += case_char(list);
	else if (c == 'd' || c == 'i')
		len += case_dec_int(list);
	else if (c == 'u')
		len += case_unsigned(list);
	else if (c == 'X')
		len += case_upperhexa(list);
	else if (c == 'x')
		len += case_lowerhexa(list);
	else if (c == '%')
		len += case_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	list;

	va_start(list, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		else
		{
			i++;
			len += conv_cases(list, str[i]);
		}
		i++;
	}
	va_end(list);
	return (len);
}
