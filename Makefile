CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = converteString.cpp main.cpp ScalarConverter.cpp TypeOfString.cpp printing.cpp
OBJ = $(SRC:.cpp=.o)
NAME = convert

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $^

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re