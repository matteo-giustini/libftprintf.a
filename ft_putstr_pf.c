/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putstr_pf.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mgiustin <marvin@42.fr>                   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 11:01:36 by mgiustin         #+#    #+#              */
/*   Updated: 2026/06/09 19:03:10 by mgiustin        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *str, int count)
{
	if (!str)
		count = ft_putstr_pf("(null)", count);
	else
	{
		while (*str)
		{
			count = ft_putchar_pf(*str, count);
			str++;
		}
	}
	return (count);
}
