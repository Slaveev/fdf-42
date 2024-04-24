NAME = libftprintf.a
CC = cc
CCFLAGS = -Wextra -Werror -Wall -std=c99

SRCS = ft_address_pointer.c ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putstr.c \
		ft_strchr.c ft_strlen.c ft_unsigned.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -I. $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
