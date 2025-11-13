NAME= get_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c 
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

compile: 
	${CC} ${CFLAGS} get_next_line.c

run:
	./a.out
cr: compile run