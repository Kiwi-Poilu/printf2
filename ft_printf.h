#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

int 	ft_printf(const char *format, ...);

typedef struct s_data
{
	int dash; //left justify
	int plus;
	int space;
	int zero; //left pad the number with zeroes instead of spaces
	int star;
	int dot;
	int width;
}				t_data;

int ft_putnbr(int nb, t_data *flags);

//ft_print_nb.c
int 	ft_print_nb(int nb, t_data *flags);
int 	ft_print_x_char(int len, char c);

//ft_putchar.c
int 	ft_putchar(char c);

void    ft_print_flags(t_data *flags);
//ft_putstr.c
int		ft_putstr(char *str, int trunc);

//ft_printf.c
int 	ft_treat(const char *format, int *i, va_list args);

//ft_print_char.c
int     ft_print_char(int c, t_data *flags);

//ft_print_string.c
int     ft_print_string(char *str, t_data *flags);

//ft_flags.c
int		ft_len_nb(int n);
void 	ft_dash(int *i, t_data *flags);
void 	ft_plus(int *i, t_data *flags);
void 	ft_space(int *i, t_data *flags);
void 	ft_zero(int *i, t_data *flags);
void 	ft_fill_flags(const char *format, int *i, va_list args, t_data *flags);
void 	ft_init_flags(t_data *flags);
int 	ft_is_digit(char c);
int 	ft_is_flag(char c);

#endif //FT_PRINTF_FT_PRINTF_H