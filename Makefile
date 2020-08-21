NAME = bsq

SRC =	sources/bsq.c \
		sources/fd_f.c \
		sources/ft_files.c \
		sources/mem_f.c \
		sources/params.c \
		sources/main.c

BUILDDIR=build

OBJ = build/*.o

FLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(FLAGS) -c
	mv *.o build
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f build/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
