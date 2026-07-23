/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:18:35 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/23 10:15:23 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_print_header(char *argv, int i);
void	ft_putstr(char *str, int fd);

long	ft_atoi(char *str)
{
	int		i;
	long	sum;

	i = 0;
	sum = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (sum);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc < 3 || argv[1][0] != '-' || argv[1][1] != 'c' || argv[1][2])
	{
		ft_putstr("./ft_tail: option requires an argument -- 'c'\n", 2);
		ft_putstr("usage: ./ft_tail -c number [file ...]\n", 2);
		return (0);
	}
	i = 0;
	while (argv[2][i])
	{
		if (!argv[2][0] || !('0' <= argv[2][i] && argv[2][i] <= '9'))
		{
			ft_putstr("./ft_tail: invalid number of bytes: '", 2);
			ft_putstr(argv[2], 2);
			ft_putstr("'\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_copy_fd(int fd, long n)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(100000000);
	bytes_read = read(fd, buf, 100000000);
	n = bytes_read - n;
	if (n < 0)
		n = 0;
	while (n < bytes_read)
	{
		write(1, &buf[n], 1);
		n++;
	}
	free(buf);
}

void	ft_error_open(int i, char *argv[])
{
	ft_putstr(argv[0], 2);
	ft_putstr(": cannot open '", 2);
	ft_putstr(argv[i], 2);
	ft_putstr("' for reading: ", 2);
	ft_putstr(strerror(errno), 2);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		fd;

	if (ft_check_args(argc, argv) == 0)
		return (1);
	i = 3;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_error_open(i, argv);
			i++;
			continue ;
		}
		if (argc > 4)
			ft_print_header(argv[i], i);
		ft_copy_fd(fd, ft_atoi(argv[2]));
		close(fd);
		i++;
	}
	return (0);
}
