/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:28:50 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/22 14:10:14 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
void	ft_putnbr_hex(int num);
void	ft_putnbr_hex_addr(int num);
void	ft_putchar(char c);
void	ft_putstr(char *str, int fd);
void	ft_print_ascii(char *row, int len);
void	ft_error_open(int i, char *argv[]);

#endif