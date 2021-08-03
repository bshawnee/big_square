NAME = big_square

CC =	gcc

SRC =	sources/bsq.c \
		sources/fd_f.c \
		sources/ft_files.c \
		sources/mem_f.c \
		sources/params.c \
		sources/main.c

OBJ = $(SRC:.c=.o)


FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(SRC) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
