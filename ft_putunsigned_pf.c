/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putunsigned_pf.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mgiustin <marvin@42.fr>                   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 11:01:34 by mgiustin         #+#    #+#              */
/*   Updated: 2026/06/09 11:01:34 by mgiustin        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
# include "printf.h"

int	ft_putunsigned_pf(unsigned int n, int count)
{
	long int	nb;

	nb = n;
	if (nb / 10)
		count = ft_putnumber_pf(nb / 10, count);
	count = ft_putchar_pf(nb % 10 + '0', count);
	return (count);
}
