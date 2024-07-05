# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 10:38:41 by aarponen          #+#    #+#              #
#    Updated: 2024/07/01 12:15:36 by aarponen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sed

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Replace.cpp

OBJ = $(SRC:.cpp=.o)

DEP = Replace.hpp

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
