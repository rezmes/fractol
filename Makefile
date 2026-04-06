NAME    = fractol
# اضافه کردن utils.c به لیست SRCS
SRCS    = main.c render.c utils.c 
OBJS    = $(SRCS:.c=.o)
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Wno-cast-function-type -std=gnu89

MLX_PATH = minilibx-linux
MLX_LIB  = $(MLX_PATH)/libmlx.a
MLX_FLAGS = $(MLX_LIB) -lXext -lX11 -lm

all: $(NAME)

$(MLX_LIB):
	-@make -C $(MLX_PATH) CFLAGS="-O3 -w -std=gnu89"

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re