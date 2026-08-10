/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:39:10 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/10 19:22:54 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_file_size(char *file)
{
	int size;
	char buf;
	int fd;

	size = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		size++;
	}
	close(fd);
	return (size);
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

int	ft_get_cols(char *buf)
{
	int	i;
	int	cols;

	i = 0;
	cols = 0;
	while(buf[i] != '\n')
		i++;
	i++;
	while(buf[i] != '\n')
	{
		cols++;
		i++;
	}
	return (cols);
}

int	ft_get_rows(char *buf)
{
	int	rows;

	rows = buf[0] - '0';
	return (rows);
}
char ft_get_empty(char *buf)
{
	return (buf[1]);
}

char ft_get_obstacle(char *buf)
{
	return (buf[2]);
}

char ft_get_full(char *buf)
{
	return (buf[3]);
}

char *ft_get_line(char *buf, int cols)
{
	char	*line;
	int	i;

	i = 0;
	line = malloc((cols + 1) * sizeof(char));
	while (i < cols)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char **ft_get_grid(char *buf)
{
	char	**grid;
	int	rows;
	int	cols;
	int	i;
	int	k;

	i = 0;
	k = 0;
	rows = ft_get_rows(buf);
	cols = ft_get_cols(buf);
	grid = malloc((rows + 1) * sizeof(char *));
	while (k < rows)
	{
		while (buf[i] && buf[i] != '\n')
			i++;
		i++;
		grid[k] = ft_get_line(&buf[i], cols);
		k++;
	}
	grid[k] = NULL;
	return (grid);
}

t_map	*ft_copy_fd(int fd, char *file)
{
	t_map	*map;
	char	*buf;
	int		bufsize;

	map = malloc(sizeof(t_map));
	bufsize = ft_file_size(file);
	buf = malloc((bufsize + 1) * sizeof(char));
	read(fd, buf, bufsize);
	map->grid = ft_get_grid(buf);
	map->cols = ft_get_cols(buf);
	map->rows = ft_get_rows(buf);
	map->empty = ft_get_empty(buf);
	map->full = ft_get_full(buf);
	map->obstacle = ft_get_obstacle(buf);
	free(buf);
	return(map);
}


void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		ft_putstr(map->grid[i]);
		ft_putchar('\n');
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

int	main(int argc, char *argv[])
{
	char	*file;
	int		i;
	int		fd;
	t_map	*map;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		file = argv[1];
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_putstr("map error\n");
		else
		{
			map = ft_copy_fd(fd, file);
			close(fd);
		}
		i++;
	}
	printf("rows: %d, cols: %d\nempty char: %c\nfull char: %c\nobstacle: %c\n", map->rows, map->cols, map->empty, map->full, map->obstacle);
	ft_print_map(map);
	return (0);
}
