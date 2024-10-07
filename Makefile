

# Paths
LIBFT_DIR = ./libft
INC = ./includes

# Compiler and Flags
UNAME := $(shell uname)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC) -I$(LIBFT_DIR) -O3 -g
LFLAGS = -L$(LIBFT_DIR) -lft -lm

# Adjust LFLAGS for non-macOS systems
ifeq ($(UNAME), Darwin)
    CC = clang
else ifeq ($(UNAME), FreeBSD)
    CC = clang
else
    LFLAGS += -lbsd
endif

# Project Files
NAME = push_swap
SRC = push_swap.c functions/swap_functions.c functions/list_functions.c	functions/push_functions.c functions/reverse_rotate_functions.c functions/rotate_functions.c functions/check_args.c
OBJ = $(SRC:.c=.o)
HEADERS = $(INC)/push_swap.h

# Targets
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a
	$(CC) $(OBJ) -o $@ $(LFLAGS)


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(LIBFT_DIR)/*.o

re: fclean all

.PHONY: all clean fclean re


