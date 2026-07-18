/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:06:42 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/18 19:34:08 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	char	*file;
	char	buf[1024];
	int	i;
	int	fd;
	int	bytes_read;

	i = 1;
	if (argc < 2)
	{
		ft_putstr(argv[0]);
		ft_putchar('\n');
		return 0;
	}
	while (i < argc)
	{
		file = argv[i];
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Cannot read file.\n");
			return (0);
		}
		bytes_read = read(fd, buf, 1024);
		write(1, buf, bytes_read);
		close(fd);
		i++;
	}
}
