#include "ft_printf.h"

int 	ft_treat(const char *format, int *i, va_list args)
{
		int out;
	t_data flags;

	out = 0;
	ft_fill_flags(format, i, args, &flags);
	if (format[*i] == '%')
		out += ft_putchar(format[(*i)++]);
	else if (format[*i] == 'c')
	    out += ft_print_char(va_arg(args, int), &flags);
	else if (format[*i] == 's')
		out += ft_print_string(va_arg(args, char *), &flags);
	else if (format[*i] == 'd' || format[*i] == 'i')
	    out += ft_print_nb(va_arg(args, int), &flags);
	(*i)++;
	return (out);
}
int 	ft_printf(const char *format, ...)
{
	//printf("ft_printf\n");
	int i;
	int out;
	va_list args;

	i = 0;
	out = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			out += ft_treat(format, &i, args);
		}
		else
			out += ft_putchar(format[i++]);
	}
	va_end(args);
	return (out);
}