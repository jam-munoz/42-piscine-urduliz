/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:09:26 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/20 20:09:49 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_putnbr_hex(int num);
void	ft_putchar(char c);

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
	char	arr[8];
	char	*base;

	base = &arr[0];
	base = basename(argv[0]);
	ft_putstr(base, 2);
	ft_putstr(": ", 2);
	ft_putstr(argv[i], 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	write(1, "\n", 1);
}

void ft_print_line(char *buf, int i, int *j)
{
	int	offset;

	offset = 0;
	ft_putchar('|');
	while (*j < i)
	{
		if (' ' <= buf[*j] && buf[*j] <= '~')
			ft_putchar(buf[*j]);
		*j = *j + 1;
	}
	ft_putstr("|\n", 1);
	while (offset < 4)
	{
		ft_putchar('0');
		zero /= ;
	}
	ft_putnbr_hex(i);
	ft_putstr("  ", 1);
}

void	ft_copy_fd(int fd)
{
	int		i;
	int		j;
	char	*buf;
	int		bytes_read;

	i = 0;
	j = 0;
	buf = malloc(100000000);
	bytes_read = read(fd, buf, 100000000);
	while (i < bytes_read)
	{
		ft_putnbr_hex((unsigned char)buf[i]);
		ft_putchar(' ');
		i++;
		if (i % 8 == 0)
			ft_putchar(' ');
		if (i % 16 == 0 || i == bytes_read)
			ft_print_line(buf, i, &j);
	}
	free(buf);
}

int	main(int argc, char *argv[])
{
	char	*file;
	int		i;
	int		fd;

	if (argc < 2)
	{
		ft_copy_fd(0);
		return (0);
	}
	i = 1;
	ft_putstr("00000000  ", 1);
	while (i < argc)
	{
		file = argv[i];
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_error_open(i, argv);
		else
		{
			ft_copy_fd(fd);
			close(fd);
		}
		i++;
	}
	return (0);
}
