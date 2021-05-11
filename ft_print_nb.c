#include "ft_printf.h"

int ft_print_x_char(int len, char c)
{
	int count;

	count = len;
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
	return (count > 0 ? count : 0);
}

int ft_print_spaces(int len, t_data *flags, int nb)
{
	int spaces;
	int zeros;
	int out;

	zeros = 0;
	spaces = 0;
	out = 0;
	if (flags->dot > len)
		zeros = flags->dot - len;
	if (flags->width > len + zeros)
		spaces = flags->width - len - zeros - (nb < 0 ? 1 : 0);
	if (flags->dash == 0)
		out += ft_print_x_char(spaces, flags->zero == 1?'0':' ');
	return (out);
}

int ft_print_zeros(int len, t_data *flags, int nb)
{
	int zeros;
	int out;

	zeros = 0;
	out = 0;
	if (flags->dot > len)
		zeros = flags->dot - len;
	if (flags->dot > len && nb < 0)
		zeros++;
	while (zeros-- > 0)
		out += ft_putchar('0');
	return (out);
}

int     ft_left_justify(int out, t_data *flags)
{
	int tmp;

	tmp = out;
	out = 0;
	if (flags->dash == 1)
	{
		while (flags->width > tmp)
		{
			out += ft_putchar(' ');
			flags->width--;
		}
	}
	return (out);
}
int 	ft_print_nb(int nb, t_data *flags)
{
    int out;

    out = 0;
    if (flags->dot > 0)
        flags->zero = 0;
    if (flags->dot == -1)
        flags->dot = 1;
    if (nb == 0 && flags->dot == 0 )
    	return (ft_print_x_char(flags->width, ' '));
    if (nb < 0 && flags->zero == 1)
    	out += ft_putchar('-');
    out += ft_print_spaces(nb == 0?1:ft_len_nb(nb) - (nb < 0 ? 1 : 0), flags, nb);
    if ((nb < 0) && flags->zero == 0)
    	out += ft_putchar('-');
    out += ft_print_zeros(nb == 0?1:ft_len_nb(nb), flags, nb);
    out += ft_putnbr(nb, flags);
    out += ft_left_justify(out, flags);
    return (out);
}

int    ft_mod(int a, int b)
{
	int r;

	r = a % (int)b;
	return ((int)(r < 0 ? 10 - r - (int)b : r));
}

int ft_putnbr(int nb, t_data *flags)
{
    int out;
    char str[17];
    int i;

    out = 0;
    if (nb == 0 && flags->dot > 0)
    {
        write(STDOUT_FILENO, "0", 1);
        return (1);
    }
    i = 16;
    while (nb != 0)
    {
        str[i--] = ft_mod(nb, 10) + '0';
        nb /= 10;
    }
    i++;
    out += write(STDOUT_FILENO, &str[i], 17 - i);
    return (out);
}