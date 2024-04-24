NAME = libft.a
CC = cc
CCFLAGS = -Wextra -Werror -Wall -std=c99

SRCS = $(wildcard *.c)
FT_PRINTF_SRCS = $(wildcard ft_printf/*.c)

OBJS = $(SRCS:.c=.o)
FT_PRINTF_OBJS = $(patsubst %.c,%.o,$(FT_PRINTF_SRCS))

BNS = ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c

BOBUS_OBJS = $(BNS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(FT_PRINTF_OBJS)
	ar rcs $(NAME) $(OBJS) $(FT_PRINTF_OBJS)

bonus: $(OBJS) $(BOBUS_OBJS)
	ar rc $(NAME) $(BOBUS_OBJS) $(OBJS)

clean:
	rm -f $(OBJS) $(FT_PRINTF_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
