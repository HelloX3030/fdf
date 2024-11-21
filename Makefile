CC := cc
CFLAGS := -Wall -Wextra -Werror # -Ofast
DEBUG_FLAGS := -g -O0
NAME := fdf

# .h files 
H_FILES := include/fdf.h

# .c files
SRC_DIR := srcs
vpath %c $(SRC_DIR)
SRC_FILES := ft_connect_tiles.c ft_draw_line.c ft_draw_map.c ft_error.c ft_free_map.c ft_get_isometric_x.c ft_get_isometric_y.c ft_get_line_count.c ft_init_map_size.c ft_malloc_map.c ft_parse_map.c ft_print_map.c ft_put_pixel_save.c ft_set_point.c ft_update_img.c main.c ft_parse_args.c

# .o files 
OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# libft 
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

# libmlx 
LIBMLX	:= lib/MLX42

# includes 
INCLUDES := -I include -I libft -I $(LIBMLX)/include
LIBS := $(LIBFT) $(LIBMLX)/build/libmlx42.a
LIB_FLAGS := -ldl -lglfw -pthread -lm

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
	@echo "Cleaning fdf"
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build
	make -C $(LIBFT_DIR) clean

# fclean
fclean:
	@echo "Fcleaning fdf"
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# re
re: fclean all

# debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: LIB_FLAGS += $(DEBUG_LDFLAGS)
debug: re

.PHONY: all clean fclean re debug
