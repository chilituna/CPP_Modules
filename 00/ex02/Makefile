# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 09:03:44 by aarponen          #+#    #+#              #
#    Updated: 2024/06/25 15:36:00 by aarponen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Account.cpp tests.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY= all re clean fclean
