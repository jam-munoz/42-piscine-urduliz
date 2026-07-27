/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/27 23:50:06 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_print_error_file(char *name, char *path)
{
	ft_print_str(2, name);
	ft_print_str(2, ": cannot open '");
	ft_print_str(2, path);
	ft_print_str(2, "' for reading: ");
	ft_print_str(2, strerror(errno));
	ft_print_str(2, "\n");
	return (1);
}

int	ft_print_file(char *name, char *path, int bytes, int file_i)
{
	int	fd;

	if (path[0] == '-' && path[1] == '\0')
	{
		fd = 0;
		path = "standard input";
	}
	else
		fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_print_error_file(name, path));
	if (file_i > 0)
		write(1, "\n", 1);
	if (file_i != -1)
	{
		ft_print_str(1, "==> ");
		ft_print_str(1, path);
		ft_print_str(1, " <==\n");
	}
	ft_print_fd(fd, bytes);
	if (fd != 0)
		close(fd);
	return (0);
}
