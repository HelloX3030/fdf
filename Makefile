CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
DEBUG_FLAGS = -g -fsanitize=address
NAME = fdf

# .h files 
H_FILES := include/fdf.h

# .c files
SRC_DIR := srcs
vpath %c $(SRC_DIR)
SRC_FILES := draw_line.c ft_error.c ft_get_isometric_x.c ft_get_isometric_y.c main.c ft_set_point.c

# .o files 
OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# libft 
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# libmlx 
LIBMLX	:= lib/MLX42

# includes 
INCLUDES := -I include -I libft -I $(LIBMLX)/include
LIBS = $(LIBFT) $(LIBMLX)/build/libmlx42.a
LIB_FLAGS = -ldl -lglfw -pthread -lm

# all
all: libmlx $(NAME)

# libmlx
libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Regular Objs
$(NAME): $(OBJ_FILES) $(LIBS)
	cp $(LIBFT) $(NAME)
	$(CC) $(OBJ_FILES) $(LIBS) $(LIB_FLAGS) -o $(NAME)

# Compile OBJ_FILES
$(OBJ_DIR)/%.o: %.c $(H_FILES) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(TEST_OBJ): %.o: %.c $(H_FILES)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# clean 
clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ_FILES)
	rm -rf $(LIBMLX)/build

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
