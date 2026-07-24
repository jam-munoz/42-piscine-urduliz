/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:09:26 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/22 14:21:00 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_hexdump_byte(unsigned char c, char *row, int *col, int *total)
{
	if (*col == 0)
	{
		ft_putnbr_hex_addr(*total);
		ft_putstr("  ", 1);
	}
	row[*col] = (char)c;
	ft_putnbr_hex(c);
	ft_putchar(' ');
	*col = *col + 1;
	*total = *total + 1;
	if (*col % 8 == 0)
		ft_putchar(' ');
	if (*col == 16)
	{
		ft_print_ascii(row, 16);
		*col = 0;
	}
}

void	ft_hexdump_flush(char *row, int *col, int *total)
{
	int	k;

	if (*total == 0)
		return ;
	if (*col > 0)
	{
		k = *col;
		while (k < 16)
		{
			ft_putstr("   ", 1);
			k++;
			if (k == 8)
				ft_putstr(" ", 1);
		}
		ft_putstr(" ", 1);
		ft_print_ascii(row, *col);
	}
	ft_putnbr_hex_addr(*total);
	ft_putstr("\n", 1);
}

void	ft_copy_fd(int fd, char *row, int *col, int *total)
{
	char	*buf;
	int		bytes_read;
	int		i;

	buf = malloc(100000000);
	bytes_read = read(fd, buf, 100000000);
	i = 0;
	while (i < bytes_read)
	{
		ft_hexdump_byte((unsigned char)buf[i], row, col, total);
		i++;
	}
	free(buf);
}

void	ft_process_arg(char *argv[], int i, char *row, int **coltotal)
{
	char	*file;
	int		fd;

	file = argv[i];
	if (file[0] == '-' && file[1] == 'C' && file[2] == '\0')
		return ;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_open(i, argv);
	else
	{
		ft_copy_fd(fd, row, coltotal[0], coltotal[1]);
		close(fd);
	}
}

int	main(int argc, char *argv[])
{
	char	row[16];
	int		i;
	int		col;
	int		total;
	int		*coltotal[2];

	col = 0;
	total = 0;
	coltotal[0] = &col;
	coltotal[1] = &total;
	if (argc < 2)
		ft_copy_fd(0, row, &col, &total);
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_process_arg(argv, i, row, coltotal);
			i++;
		}
	}
	ft_hexdump_flush(row, &col, &total);
	return (0);
}
