NAME = phonebook
SRCS = main.cpp contact.cpp phonebook.cpp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean: $(NAME)
	rm $(NAME)

fclean: clean

re: fclean all