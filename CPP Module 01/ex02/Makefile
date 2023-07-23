NAME = brain
SRCS = *.cpp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(FLAGS) -o $(NAME)

clean:
	rm -fr $(NAME)

fclean: clean

re: fclean all

.PHONY: clean fclean re