/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:33:05 by ashahin           #+#    #+#             */
/*   Updated: 2022/07/29 22:33:05 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
// conversion cases
int		conv_cases(va_list list, const char c);
int		case_string(va_list list);
int		case_pointer(va_list list);
int		case_char(va_list list);
int		case_dec_int(va_list list);

int		case_unsigned(va_list list);
int		case_upperhexa(va_list list);
int		case_lowerhexa(va_list list);
int		case_percent(void);
// ft_itohexa
size_t	hexa_len(unsigned long n);
void	ft_str_toupper(char *str);
int		ft_hexa_dup( unsigned long n);
char	*ft_hexatoa(unsigned long n);
// ft_printf_util
size_t	get_long_len(long n);
void	ft_put_unsigned_nbr(unsigned int n);

#endif // !FT_PRINF.H
