/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_u_X_x_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:19:06 by ashahin           #+#    #+#             */
/*   Updated: 2022/09/10 05:43:44 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	case_unsigned(va_list list)
{
	unsigned int	unsigned_int;
	size_t			len;

	unsigned_int = va_arg(list, unsigned int);
	len = get_long_len((long) unsigned_int);
	ft_put_unsigned_nbr(unsigned_int);
	return (len);
}

int	case_upperhexa(va_list list)
{
	unsigned int	hexa;
	size_t			len;
	char			*hexastr;

	hexa = va_arg(list, unsigned int);
	len = hexa_len((unsigned int) hexa);
	hexastr = ft_hexatoa(hexa);
	ft_str_toupper(hexastr);
	ft_putstr_fd(hexastr, 1);
	free(hexastr);
	return (len);
}

int	case_lowerhexa(va_list	list)
{
	unsigned int	hexa;
	size_t			len;
	char			*hexastr;

	hexa = va_arg(list, unsigned int);
	len = hexa_len((unsigned int) hexa);
	hexastr = ft_hexatoa(hexa);
	ft_putstr_fd(hexastr, 1);
	free(hexastr);
	return (len);
}

int	case_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
