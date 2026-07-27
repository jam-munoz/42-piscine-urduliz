/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_readable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/28 00:28:09 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_readable(t_data *data)
{
	int	i;

	i = -1;
	write(1, "|", 1);
	while (++i < data->size)
	{
		if (32 <= data->buffer[i] && data->buffer[i] <= 126)
			write(1, data->buffer + i, 1);
		else
			write(1, ".", 1);
	}
	write(1, "|", 1);
	return ;
}
