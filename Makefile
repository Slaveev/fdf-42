# export ASAN_OPTIONS=detect_leaks=1

CFLAGS = -Wextra -Werror -Wall -std=c99 # -g -fsanitize=address -fno-omit-frame-pointer
SRCS = main.c read_file.c utils.c draw.c draw_utils.c color.c operations.c isometrics.c resized_map.c operations1.c
OBJS = $(SRCS:.c=.o)

NAME = fdf

all: $(NAME)

$(NAME): $(OBJS)
	echo "Compiling libft"
	make -C libft/
	echo "Compiling mlx"
	make -C minilibx_macos/
	gcc $(CFLAGS) $^ -L minilibx_macos/ -Llibft/ -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
