int ft_printptr_pf(void *ptr, int count)
{
    unsigned long int p;

    p = (unsigned long int)ptr;
    if (!p)
    {
        count = ft_putstr_pf("(nil)", count);
        return (count);
    }
    count = ft_putstr_pf("0x", count);
    count = ft_printhex_pfm(p, 'x', count);
    return (count);
}