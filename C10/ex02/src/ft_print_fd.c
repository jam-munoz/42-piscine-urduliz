/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/27 23:50:13 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_push_str(char *str, char c, int bytes, int size)
{
	int	i;

	if (size < bytes)
	{
		str[size] = c;
		return ;
	}
	i = -1;
	while (++i < bytes - 1)
		str[i] = str[i + 1];
	str[i] = c;
	return ;
}

void	ft_print_fd(int fd, int bytes)
{
	char	c;
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * bytes);
	size = 0;
	while (1)
	{
		if (read(fd, &c, 1) != 1)
		{
			write(1, buffer, size);
			free(buffer);
			return ;
		}
		ft_push_str(buffer, c, bytes, size);
		if (size < bytes)
			size++;
	}
	return ;
}
