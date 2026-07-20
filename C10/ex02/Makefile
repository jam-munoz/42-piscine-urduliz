# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/18 18:19:44 by joamunoz          #+#    #+#              #
#    Updated: 2026/07/20 14:14:41 by joamunoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes

MY_SOURCES = ft_tail.c helpers.c
MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
