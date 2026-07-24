/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/22 14:10:24 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_error_open(int i, char *argv[])
{
	ft_putstr(argv[0], 2);
	ft_putstr(": ", 2);
	ft_putstr(argv[i], 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	write(2, "\n", 1);
}

void	ft_print_ascii(char *row, int len)
{
	int	i;

	i = 0;
	ft_putchar('|');
	while (i < len)
	{
		if (' ' <= row[i] && row[i] <= '~')
			ft_putchar(row[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putstr("|\n", 1);
}
