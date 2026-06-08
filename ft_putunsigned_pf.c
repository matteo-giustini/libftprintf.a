int ft_putunsigned_pf(unsigned int n, int count)
{
    long int nb;

    nb = n;
    if (nb / 10)
       count = ft_putnumber_pf(nb / 10, count);
    count = ft_putchar_pf(nb % 10 + '0', count);
    return(count);
}
