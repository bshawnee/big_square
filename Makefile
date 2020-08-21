NAME = bsq

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c

BUILDDIR = build

OBJ = $(SRC:.c = .o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(SRC) -I includes/
	$(CC) *.o -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
