/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printptr_pf.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mgiustin <marvin@42.fr>                   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 11:01:44 by mgiustin         #+#    #+#              */
/*   Updated: 2026/06/09 11:01:44 by mgiustin        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
# include "printf.h"

int	ft_printptr_pf(void *ptr, int count)
{
	unsigned long int	p;

	p = (unsigned long int) ptr;
	if (!p)
	{
		count = ft_putstr_pf("(nil)", count);
		return (count);
	}
	count = ft_putstr_pf("0x", count);
	count = ft_printhex_pfm(p, 'x', count);
	return (count);
}
