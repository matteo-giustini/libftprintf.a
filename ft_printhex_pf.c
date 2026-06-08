
int ft_printhex_pfm(unsigned long int n, char format; int count)
{
    char    *base;

    if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
    if (n / 16)
        count = ft_printhex_pf(n / 16, format, count);
    count = ft_putchar_pf(base[n % 16], count);
    return(count);
}