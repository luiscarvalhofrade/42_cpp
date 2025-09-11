CC = c++

CFLAGS = -Werror -Wextra -Wall -std=c++98

NAME = sed

SRC =	main.cpp \
		Sed.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re