NAME	= fixed

SOURCES	= main.cpp Fixed.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

.c.o:
	$(CC) $(FLAGS) -c -o $(<:.c=.0)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)