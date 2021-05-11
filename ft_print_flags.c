#include "ft_printf.h"

void    ft_print_flags(t_data *flags)
{
    printf("flags->dash = %d\n", flags->dash);
    printf("flags->plus = %d\n", flags->plus);
    printf("flags->space = %d\n", flags->space);
    printf("flags->zero = %d\n", flags->zero);
    printf("flags->star = %d\n", flags->star);
    printf("flags->dot = %d\n", flags-> dot);
    printf("flags->width = %d\n", flags->width);
}