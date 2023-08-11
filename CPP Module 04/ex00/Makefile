NAME	= Animal

SOURCES	= main.cpp Cat.cpp Animal.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CC		= c++ 
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all