NAME := ./a.out

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC := init_cub3d.c main.c parser_mocking.c

LIB_DIR := mlx
LIBRARY := -L$(LIB_DIR) -lmlx -lXext -lX11 -lm -lz
HEADER := cub3d.h

all: $(NAME)

$(NAME): $(LIB_DIR)/libmlx.a $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) $(LIBRARY) -o $(NAME)

$(LIB_DIR)/libmlx.a:
	@$(MAKE) -C $(LIB_DIR)

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(LIB_DIR)/*.o $(LIB_DIR)/libmlx.a

re: fclean all
