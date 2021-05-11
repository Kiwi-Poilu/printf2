cmake_minimum_required(VERSION 3.19)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_printf main.c
        ft_flags.c
        ft_print_char.c
        ft_print_nb.c
        ft_print_string.c
        ft_printf.c
        ft_putchar.c
        ft_print_flags.c
        )