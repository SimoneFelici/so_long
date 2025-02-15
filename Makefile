NAME = so_long
CC = clang
CFLAGS = #-Wall -Wextra -Werror

SRC = main.c player_input.c draw_texture.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libraries/libft
MLX_DIR = ./libraries/minilibx-linux/

LIBFT = $(LIBFT_DIR)/libft.a

MLX_FLAGS = -L ${MLX_DIR} -lmlx_Linux -I${MLX_DIR} -lXext -lX11 -lm -lz 

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
