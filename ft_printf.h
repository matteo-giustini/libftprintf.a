/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mgiustin <marvin@42.fr>                   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/09 11:02:02 by mgiustin         #+#    #+#              */
/*   Updated: 2026/06/09 19:06:07 by mgiustin        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	formatter(va_list va, const char c, int count);
int	ft_printhex_pf(unsigned long int n, char format, int count);
int	ft_printptr_pf(void *ptr, int count);
int	ft_putchar_pf(char c, int count);
int	ft_putnumber_pf(int n, int count);
int	ft_putstr_pf(char *str, int count);
int	ft_putunsigned_pf(unsigned int n, int count);
int	ft_putunsigned_pf(unsigned int n, int count);
int	ft_printf(const char *str, ...);

#endif
