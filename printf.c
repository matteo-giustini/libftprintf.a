/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   printf.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mgiustin <marvin@42.fr>                   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 11:01:26 by mgiustin         #+#    #+#              */
/*   Updated: 2026/06/09 11:01:26 by mgiustin        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
# include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list va;
	int	count;
	int	i;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			count = formatter(va, str[i], count);
		}
		else
			count = ft_putchar_pf(str[i], count);
		i++;
	}
	va_end(va);
	return (count);
}
