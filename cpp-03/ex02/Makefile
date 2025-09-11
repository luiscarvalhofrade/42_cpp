CC = c++

CLFAGS = -Wall -Wextra -Werror -std=c++98

NAME = claptrap

SRC = 	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CLFAGS) $(OBJ) -o $@

clean:	
		rm -f $(OBJ)

fclean: clean	
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re