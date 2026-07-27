# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/18 18:19:44 by joamunoz          #+#    #+#              #
#    Updated: 2026/07/28 00:27:32 by joamunoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump

CFILES = main.c \
	ft_dump_fd.c \
	ft_dump_files.c \
	ft_print_addr.c \
	ft_print_hex.c \
	ft_print_line.c \
	ft_print_readable.c \
	ft_print_str.c \
	ft_read_line.c \
	ft_strcmp.c
SRCS = $(addprefix src/, $(CFILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -Iinclude $(OBJS) -o $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -Iinclude -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
