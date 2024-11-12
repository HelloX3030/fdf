CC = cc
C_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address
NAME = libft.a

SRC_FILES := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_isascii.c ft_memchr.c
OBJ_FILES := $(SRC_FILES:.c=.o)

BONUS_SRC_FILES := ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJ_FILES := $(BONUS_SRC_FILES:.c=.o)

# all
all: $(NAME)

# Regular Objs
$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

# Compile OBJ_FILES
$(OBJ_FILES): %.o: %.c libft.h
	$(CC) $(C_FLAGS) -c $< -o $@

# Compile BONUS_OBJ_FILES
$(BONUS_OBJ_FILES): %.o: %.c libft.h
	$(CC) $(C_FLAGS) -c $< -o $@

# clean 
clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)  # Clean both regular and bonus object files

# fclean
fclean: clean
	rm -f $(NAME)

# re
re: fclean all

# bonus
bonus: $(BONUS_OBJ_FILES)
	ar rcs $(NAME) $(BONUS_OBJ_FILES)

# debug
debug: $(C_FLAGS) += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re bonus debug
