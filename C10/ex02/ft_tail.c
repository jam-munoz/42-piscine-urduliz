/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:18:35 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/18 20:44:10 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	len;
	int	i;

	len = 0;
	while(s1[len])
		len++;
	i = 0;
	while (i <= len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int ft_atoi(char *str)
{
	int i = 0;
	int sum = 0;
	int sign = -1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			sign = 1;
		i++;
	}
	while(str[i] && ('0' <= str[i] && str[i] <= '9'))
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (sign * sum);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int main(int argc, char *argv[])
{
	char	*file;
	char	buf[1024];
	int	i;
	int	j;
	int	fd;
	int	bytes_read;
	int	newline;

	i = 1;
	newline = 0;
	if (argc < 2)
	{
		ft_putstr(argv[0]);
		ft_putchar('\n');
		return 0;
	}
	if (argc == 2)
	{
		file = argv[i];
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Cannot read file.\n");
			return (0);
		}
		bytes_read = read(fd, buf, 1024);
		j = bytes_read - 3;
		while(j > 0 && newline < 9)
		{
			if (buf[--j] == '\n')
				newline++;
		}
		while (j < bytes_read)
			ft_putchar(buf[j++]);
		i++;
		return 0;
	}
	if (ft_strcmp(argv[1], "-c") == 0)
	{
		i += 2;
	}
	if (ft_strcmp(argv[1], "-c") == 0)
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
			{
				ft_putstr("==> ");
				ft_putstr(argv[i]);
				ft_putstr(" <==\n");
			}
			bytes_read = read(fd, buf, 1024);
			j = bytes_read + ft_atoi(argv[2]);
			while (j < bytes_read - 1)
				ft_putchar(buf[j++]);
			ft_putchar('\n');
			close(fd);
			i++;
		}
	}
	if (ft_strcmp(argv[1], "-c") == 0)
		return 0;
	while (i < argc)
	{
		file = argv[i];
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Cannot read file.\n");
			return (0);
		}
		ft_putstr("==> ");
		ft_putstr(argv[i]);
		ft_putstr(" <==\n");
		bytes_read = read(fd, buf, 1024);
		j = bytes_read - 2;
		while(j > 0 && newline < 9)
		{
			j--;
			if (buf[j] == '\n')
				newline++;
		}
		while (j < bytes_read)
			ft_putchar(buf[j++]);
		ft_putchar('\n');
		close(fd);
		i++;
	}
}
//si pongo uno largo primero el segundo solo imprime dos bytes.