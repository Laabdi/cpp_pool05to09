SRC = 	AForm.cpp \
		Bureaucrat.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		main.cpp

NAME = execute_me

OBJ = $(SRC:.cpp=.o)

FLAGS = -std=c++98 -Wall -Werror -Wextra

CC = c++

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all

.PHONY: all clean fclean re