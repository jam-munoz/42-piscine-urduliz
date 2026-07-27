/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/28 00:28:16 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_hexchar(char c)
{
	if (c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	write(1, &c, 1);
	return ;
}

void	ft_print_byte(char c)
{
	ft_print_hexchar((unsigned char)c / 16);
	ft_print_hexchar((unsigned char)c % 16);
	return ;
}

void	ft_print_hex_simple(t_data *data)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i > 0)
			write(1, " ", 1);
		if (i >= data->size)
			write(1, "    ", 4);
		else
		{
			if (i == data->size - 1)
				ft_print_byte(0);
			else
				ft_print_byte(data->buffer[i + 1]);
			ft_print_byte(data->buffer[i]);
		}
		i += 2;
	}
	return ;
}

void	ft_print_hex_details(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (i == 8)
			write(1, " ", 1);
		if (i > 0)
			write(1, " ", 1);
		if (i >= data->size)
			write(1, "  ", 2);
		else
			ft_print_byte(data->buffer[i]);
	}
	return ;
}

void	ft_print_hex(t_data *data, int details)
{
	if (details)
		ft_print_hex_details(data);
	else
		ft_print_hex_simple(data);
	return ;
}
