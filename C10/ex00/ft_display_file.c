/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:16:43 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/19 20:04:39 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
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

int	main(int argc, char *argv[])
{
	char	*file;
	char	buf[1024];
	int		fd;
	int		bytes_read;

	if (argc < 2)
		ft_putstr("File name missing.\n", 2);
	if (argc > 2)
		ft_putstr("Too many arguments.\n", 2);
	if (argc != 2)
		return (-1);
	file = argv[1];
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (1);
	}
	bytes_read = read(fd, buf, 1024);
	while (bytes_read > 0)
	{
		write(1, buf, bytes_read);
		bytes_read = read(fd, buf, 1024);
	}
	close(fd);
}
