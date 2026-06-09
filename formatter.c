/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   formatter.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mgiustin <marvin@42.fr>                   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 11:01:48 by mgiustin         #+#    #+#              */
/*   Updated: 2026/06/09 19:02:44 by mgiustin        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formatter(va_list va, const char c, int count)
{
	if (c == 'c')
		count = ft_putchar_pf(va_arg(va, int), count);
	else if (c == 's')
		count = ft_putstr_pf(va_arg(va, char *), count);
	else if (c == 'i' || c == 'd')
		count = ft_putnumber_pf(va_arg(va, int), count);
	else if (c == 'u')
		count = ft_putunsigned_pf(va_arg(va, unsigned int), count);
	else if (c == 'X' || c == 'x')
		count = ft_printhex_pf(va_arg(va, unsigned int), c, count);
	else if (c == 'p')
		count = ft_printptr_pf(va_arg(va, void *), count);
	else if (c == '%')
		count = ft_putchar_pf('%', count);
	else
		count = ft_putchar_pf(c, count);
	return (count);
}
