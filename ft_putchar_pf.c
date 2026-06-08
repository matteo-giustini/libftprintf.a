int ft_putchar_pf(char c, int count)
{
    count++;
    write(1, &c, 1);
    return(count);
}