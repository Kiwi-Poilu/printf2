#include "ft_printf.h"

int		ft_len_nb(int n)
{
    int i;

    i = 0;
    if (n == 0)
    	i++;
    if (n < 0)
        i++;
    while (n != 0)
    {
        n/=10;
        i++;
    }
    return (i);
}

void 	ft_width(const char *format, int *i, va_list args, t_data *flags)
{
	if (format[*i] == '*')
	{
		flags->width = va_arg(args, int);
		(*i)++;
	}
	else
	{
		flags->width = atoi((char *)format + *i);
		(*i)+= ft_len_nb(flags->width);
	}
}

void 	ft_dot(const char *format, int *i, va_list args, t_data *flags)
{
	if (ft_is_digit(format[(*i) + 1]))
		(*i)++;
	if (format[*i] == '*')
	{
		flags->dot = va_arg(args, int);
		(*i)++;
	}
	else
	{
		flags->dot = atoi((char *)format + *i);
		(*i) += ft_len_nb(flags->dot);
	}
}

void 	ft_dash(int *i, t_data *flags)
{
	flags->dash = 1;
	(*i)++;
}

void 	ft_plus(int *i, t_data *flags)
{
	flags->plus = 1;
	(*i)++;
}

void 	ft_space(int *i, t_data *flags)
{
	flags->space = 1;
	(*i)++;
}

void		ft_zero(int *i, t_data *flags)
{
	flags->zero = 1;
	(*i)++;
}

int 	ft_is_digit(char c)
{
	//printf("ft_is_digit\n");
	if (c >= '0' && c <= '9')
		return (1);
	return(0);
}

int 	ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '*' || c == '.')
		return (1);
	return (0);
}

void 	ft_init_flags(t_data *flags)
{
	//printf("ft_init_flags\n");
	flags->dash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->dot = -1;
	flags->width = 0;
}

void 	ft_fill_flags(const char *format, int *i, va_list args, t_data *flags)
{
	//printf("ft_fill_flags\n");
	ft_init_flags(flags);

	while (ft_is_flag(format[*i]) || ft_is_digit(format[*i]))
	{
		if (format[*i] == '-')
			ft_dash(i, flags);
		if (format[*i] == '+')
			ft_plus(i, flags);
		if (format[*i] == ' ')
			ft_space(i, flags);
		if (format[*i] == '0')
			ft_zero(i, flags);
		if (ft_is_digit(format[*i]) || format[*i] == '*')
			ft_width(format, i, args, flags);
		if (format[*i] == '.')
			ft_dot(format, i, args, flags);
	}
}