CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
      ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c
OBJ = $(SRC:.c=.o)

NAME = libft.a

TEST = test
MAIN = main.c
MAIN_O = main.o

.PHONY: all test clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Build the test: compile main.c to main.o then link main.o with libft.a
test: $(NAME) $(MAIN_O)
	$(CC) $(CFLAGS) $(MAIN_O) $(NAME) -o $(TEST)

# Compile main.c into main.o (rebuild if header changes)
$(MAIN_O): $(MAIN) libft.h
	$(CC) $(CFLAGS) -c $(MAIN) -o $(MAIN_O)

# Generic rule to build library object files and depend on libft.h
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(MAIN_O)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all
# LINKING 
# Linking is the process of combining object files (.o) and libraries (.a or .so) 
# a final executable or another library.
# It is the step after compiling your source code, and it is handled by a tool called the
# linker (usually ld, but often invoked via gcc).
