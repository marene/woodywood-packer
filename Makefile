NAME =					woody_woodpacker
CC =					clang
INCLUDES_DIR =			./includes/
SRCS_DIR =				./srcs/
OBJ_DIR =				./obj/
LIBFT_DIR =				./libft
LIBFT_INCLUDES =		$(LIBFT_DIR)/includes/
LIBFT =					$(LIBFT_DIR)/libft.a
CFLAGS =				-Wall -Wextra -Werror -I$(INCLUDES_DIR) -I$(LIBFT_INCLUDES) -c -g -o
LDFLAGS =				-L$(LIBFT_DIR) -lft -o
SRCS =					main.c\
						pack.c\
						packer_destruct.c\
						packer_init.c\
						packer_read.c
OBJ =					$(SRCS:.c=.o)

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(CC) $(LDFLAGS) $@ $^

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: clean fclean
	make -C $(LIBFT_DIR) fclean
	make all

.PHONY: all clean fclean re
