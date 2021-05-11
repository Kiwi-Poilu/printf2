#include "ft_printf.h"

int		main(void)
{
    int ret_ft;
    int ret_man;
	ret_ft = ft_printf("hello, %s.\n", NULL);
	ret_man = printf("hello, %s.\n", NULL);
	printf("ft_printf = %d\n", ret_ft - 1);
	printf("printf = %d\n", ret_man - 1);
}