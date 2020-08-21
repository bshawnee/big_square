NAME = bsq

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC =	sources/bsq.c \
		sources/fd_f.c \
		sources/ft_files.c \
		sources/mem_f.c \
		sources/params.c \
		sources/main.c
OBJ = $(SRC:.c = .o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) -c $(SRC) -I includes/
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
