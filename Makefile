NAME = fractol
SRC = main.c parse.c render.c hooks.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAG = -Wall -Wextra -Werror
MLX = -Lmlx_linux -lmlx -lXert -lX11 -lm
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) -o $(NAME)
clean: rm -f $(OBJ)
fclean: clean; rm -f $(NAME)
re: fclean all
