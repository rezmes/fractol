NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c init.c hooks.c render.c fractals.c utils.c
OBJS		= $(SRCS:.c=.o)

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a

X11_INC		= $(shell for p in /usr/include /usr/include/X11 /usr/X11/include /usr/local/include /usr/local/include/X11; do \
				if [ -f "$$p/X11/Xlib.h" ] && [ -f "$$p/X11/extensions/XShm.h" ]; then \
					echo $$p; break; \
				fi; \
			done)

MLX_LINK	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
MLX_COMPAT	= -O3 -w -std=gnu89 -I$(X11_INC)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LINK) -o $(NAME)

$(MLX_LIB):
	@if [ -z "$(X11_INC)" ]; then \
		echo "Error: X11 headers not found."; \
		exit 1; \
	fi
	@$(MAKE) -C $(MLX_DIR) -f Makefile.mk INC=$(X11_INC) >/dev/null 2>&1 || \
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk INC=$(X11_INC) CFLAGS="$(MLX_COMPAT)"

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) -f Makefile.mk clean INC=$(X11_INC) >/dev/null 2>&1 || true

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re