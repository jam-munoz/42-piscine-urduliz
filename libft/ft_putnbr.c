/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:14:02 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/10 18:49:07 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char			buf[11];
	int				i;
	unsigned int	n;

	i = 11;
	n = nb;
	if (nb < 0)
		n = -n;
	while (n >= 10)
	{
		buf[--i] = (n % 10) + '0';
		n = n / 10;
	}
	buf[--i] = n + '0';
	if (nb < 0)
		buf[--i] = '-';
	write(1, buf + i, 11 - i);
}
