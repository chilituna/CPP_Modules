# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/07 10:56:33 by aarponen          #+#    #+#              #
#    Updated: 2024/07/15 15:21:31 by aarponen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJS = $(SRCS:.cpp=.o)

INCLUDES = Fixed.hpp Point.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
