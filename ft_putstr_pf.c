/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putstr_pf.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mgiustin <marvin@42.fr>                   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 11:01:36 by mgiustin         #+#    #+#              */
/*   Updated: 2026/06/09 11:01:36 by mgiustin        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
# include "printf.h"

int	ft_putstr_pf(char *str, int count)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		ft_putchar_pf(*str, count);
		str++;
	}
}
