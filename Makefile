NAME= get_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

SRC = get_next_line.c utils.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c get_next_line.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) ./a.out

fclean: clean
	rm -f $(NAME)

re: fclean all 
