/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:06:42 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/20 14:33:14 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

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

void	ft_copy_fd(int fd)
{
	char	buf[1024];
	int		bytes_read;

	bytes_read = read(fd, buf, 1024);
	while (bytes_read > 0)
	{
		write(1, buf, bytes_read);
		bytes_read = read(fd, buf, 1024);
	}
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
