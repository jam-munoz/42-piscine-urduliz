# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/25 17:54:04 by joamunoz          #+#    #+#              #
#    Updated: 2026/07/30 11:51:25 by joamunoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes

MY_SOURCES = main.c ft.c ft_print_numbers.c ft_def.c ft_def_million.c
MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
