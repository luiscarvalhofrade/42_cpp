CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	Zombie.cpp \
		main.cpp \
		zombieHorde.cpp

OBJ = $(SRC:.cpp=.o)

NAME = zombie2

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
