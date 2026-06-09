/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printhex_pf.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mgiustin <marvin@42.fr>                   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 11:01:46 by mgiustin         #+#    #+#              */
/*   Updated: 2026/06/09 11:01:46 by mgiustin        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
# include "printf.h"

int	ft_printhex_pfm(unsigned long int n, char format; int count)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (n / 16)
		count = ft_printhex_pf(n / 16, format, count);
	count = ft_putchar_pf(base[n % 16], count);
	return (count);
}
