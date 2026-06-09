#include <stdio.h>
#include "ft_printf.h"

int main()
{
    int count;
    count = 0;
    count += ft_putchar_pf('s', count);
    printf("%d", count);
}