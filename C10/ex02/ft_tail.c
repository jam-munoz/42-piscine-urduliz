/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:18:35 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/19 20:03:57 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sum;
	int	sign;

	i = 0;
	sum = 0;
	sign = -1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			sign = 1;
		i++;
	}
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (sign * sum);
}

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

void	ft_print_header(char *argv, int i)
{
	if (i == 3)
		ft_putstr("==> ");
	else
		ft_putstr("\n==> ");
	ft_putstr(argv);
	ft_putstr(" <==\n");
}

void	ft_copy_fd(int fd, int n)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(1000000000);
	bytes_read = read(fd, buf, 1000000000);
	n += bytes_read;
	while (n < bytes_read)
	{
		write(1, &buf[n], 1);
		n++;
	}
	free(buf);
}

int	main(int argc, char *argv[])
{
	char	*file;
	int		i;
	int		fd;

	i = 3;
	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
		while (i < argc)
		{
			file = argv[i];
			fd = open(file, O_RDONLY);
			if (fd == -1)
			{
				ft_putstr("Cannot read file.\n");
				return (0);
			}
			if (argc > 4)
				ft_print_header(argv[i], i);
			ft_copy_fd(fd, ft_atoi(argv[2]));
			close(fd);
			i++;
		}
	}
}
//algunos ponen 5 letras otros 4 y no se como manejar la nueva linea final
//solo funciona con -c pero el ejercicio dice textual "The only option you need to handle is -c, but you don’t need to handle the ’+’ or ’-’ signs. All tests will be conducted using the -c option."
//falta agregar el mensaje "tail: invalid number of bytes: " "tail: option requires an argument -- 'c'"