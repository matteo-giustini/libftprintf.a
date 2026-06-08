int ft_putstr_pf(char *str, int count)
{
    if(!str)
        return NULL;
    while(*str)
    {
        ft_putchar_pf(*str, count);
        str++; 
    }
}