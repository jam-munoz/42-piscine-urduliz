/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/28 00:28:20 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_addr(unsigned int addr, int i, int details)
{
	char	c;

	if (i < (7 - (details == 0)))
		ft_print_addr(addr / 16, i + 1, details);
	c = addr % 16;
	if (c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	write(1, &c, 1);
	return ;
}
