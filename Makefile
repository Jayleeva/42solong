NAME = so_long
LIBFT = libft
LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/$(LIBFT)
MLX_DIR = ./minilibx_linux
MLX_LIB = $(MLX_DIR)/libmlx.a

SRC_DIR = ./src
SRC = display.c parsing.c flood.c is_invalid.c is_playable.c is_playable_utils.c create_window.c load_images.c inputs.c move.c update_tiles.c
OBJ = $(SRC:.c=.o)

SRC := $(addprefix $(SRC_DIR)/, $(SRC))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./inc -I ./libft/inc
MLX_FLAGS = -lXext -lX11
INCLUDES = -I/usr/include -Imlx

all: $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJ) $(LIBFT_LIB)
	@${CC} ${CFLAGS} ${OBJ} $(LIBFT_LIB) $(MLX_LIB) -o $(NAME) $(MLX_FLAGS)

$(LIBFT_LIB):
	@${MAKE} -C libft

$(MLX_LIB):
	@${MAKE} -C $(MLX_DIR)

clean:
	@${MAKE} -C libft fclean
	@${MAKE} -C $(MLX_DIR) clean
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean re