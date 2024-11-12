CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address
NAME = libftprintf.a

H_FILES := include/ft_printf.h
SRC_DIR := srcs

SRC_FILES := ft_printf.c ft_print_c.c ft_print_s.c ft_print_i.c ft_print_p.c ft_print_u.c ft_print_x.c ft_print_xx.c ft_print_per.c ft_print_l.c

TEST_NAME = test
TEST_SRC = test.c

vpath %c $(SRC_DIR)

OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
TEST_OBJ = $(TEST_SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_FLAGS = -I libft -lft

INCLUDES := -I include -I libft

# all
all: $(NAME)

# Regular Objs
$(NAME): $(OBJ_FILES) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $@ $^ 

# Compile OBJ_FILES
$(OBJ_DIR)/%.o: %.c $(H_FILES) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

# test 
test: $(TEST_OBJ) $(NAME)
	$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_OBJ) -L. -lftprintf

$(TEST_OBJ): %.o: %.c $(H_FILES)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# clean 
clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ_FILES)

# fclean
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# re
re: fclean all

# debug
debug: $(CFLAGS) += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re bonus debug
