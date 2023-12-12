NAME = a.out

CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp WrongCat.cpp WrongAnimal.cpp Dog.cpp Cat.cpp Animal.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re