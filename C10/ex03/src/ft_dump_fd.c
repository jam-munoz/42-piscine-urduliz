/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/28 00:28:30 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_dump_fd(t_data *data, int fd, int details)
{
	int	result;

	result = 1;
	while (result)
	{
		result = ft_read_line(fd, data);
		if (result < 0)
			return (1);
		if (data->size == 16)
			ft_print_line(data, details);
	}
	return (0);
}
