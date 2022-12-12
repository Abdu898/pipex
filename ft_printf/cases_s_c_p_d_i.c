/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_s_c_p_d_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:33:41 by ashahin           #+#    #+#             */
/*   Updated: 2022/09/10 05:39:54 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	case_string(va_list list)
{
	char	*str;
	size_t	strlen;

	str = va_arg(list, char *);
	if (!str)
	{
		strlen = 6;
		ft_putstr_fd("(null)", 1);
		return (strlen);
	}
	else
	{
		strlen = ft_strlen(str);
		ft_putstr_fd(str, 1);
		return (strlen);
	}
}

int	case_pointer(va_list list)
{
	void			*p;
	char			*strptr;
	size_t			len;
	unsigned long	p_int;

	p = va_arg(list, void *);
	if (!p)
	{
		write(1, "0x0", 3);
		return (3);
	}
	p_int = (unsigned long) p;
	len = hexa_len(p_int) + 2;
	strptr = ft_hexatoa(p_int);
	write(1, "0x", 2);
	ft_putstr_fd(strptr, 1);
	free(strptr);
	return (len);
}

int	case_char(va_list list)
{
	char	c;

	c = va_arg(list, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	case_dec_int(va_list list)
{
	int		dec_int;
	size_t	len;

	dec_int = va_arg(list, int);
	len = get_long_len((long) dec_int);
	ft_putnbr_fd(dec_int, 1);
	return (len);
}
