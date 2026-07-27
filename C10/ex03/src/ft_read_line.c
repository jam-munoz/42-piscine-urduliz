/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/28 00:28:01 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_read_line(int fd, t_data *data)
{
	int	size;

	if (data->size == 16)
		return (0);
	size = read(fd, data->buffer + data->size, 16 - data->size);
	if (size > 0)
		data->size += size;
	return (size);
}
