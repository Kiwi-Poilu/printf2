NAME = libftprintf.a

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRCS =	./ft_flags.c \
		./ft_print_char.c \
		./ft_print_nb.c \
		./ft_printf.c \
		./ft_putchar.c \
		./ft_print_string.c \
		./main.c \
		./ft_print_flags.c


OBJS = ${SRCS:.c=.o}

all : $(NAME)

.c.o: 
		$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) 

clean : 
	rm -f $(OBJS) 

fclean : clean 
	rm -f $(NAME)

re : fclean all