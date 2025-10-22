CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
      ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
      ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c \
      ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
      ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

# ✅ fixed typo: was ft_lstlast_bonus,c (should be .c)
SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c \
              ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
				ft_lstiter_bonus.c ft_lstmap_bonus.c 
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a

TEST = test
MAIN = main.c
MAIN_O = main.o

.PHONY: all clean fclean re bonus test norm so

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJS_BONUS)

test: bonus $(MAIN_O)
	$(CC) $(CFLAGS) $(MAIN_O) $(NAME) -o $(TEST)

norm:
	norminette $(SRC) $(SRCS_BONUS)
	norminette -R CheckDefine libft.h

so: $(OBJ) $(OBJS_BONUS)
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRCS_BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJS_BONUS)

$(MAIN_O): $(MAIN) libft.h
	$(CC) $(CFLAGS) -c $(MAIN) -o $(MAIN_O)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJS_BONUS) $(MAIN_O)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all
# LINKING 
# Linking is the process of combining object files (.o) and libraries (.a or .so) 
# a final executable or another library.
# It is the step after compiling your source code, and it is handled by a tool called the
# linker (usually ld, but often invoked via gcc).
