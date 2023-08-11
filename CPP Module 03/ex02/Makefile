NAME	= FragTrap

SOURCES	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp 

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