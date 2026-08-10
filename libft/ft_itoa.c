/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 09:35:48 by joamunoz          #+#    #+#             */
/*   Updated: 2026/08/10 18:54:45 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_digit_count(int nb)
{
	unsigned int	n;

	n = nb;
	if (nb < 0)
		n = -n;
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	return (10);
}

char	*ft_itoa(int nb)
{
	long	n;
	int		digits;
	char	*out;
	int		i;
	int		start;

	n = nb;
	digits = ft_digit_count(nb);
	out = malloc(digits + 1);
	i = 0;
	start = 0;
	if (n < 0)
	{
		n *= -1;
		out[i++] = '-';
		start = 1;
	}
	out[digits--] = '\0';
	while (digits >= start)
	{
		out[digits--] = (n % 10) + '0';
		n /= 10;
	}
	return (out);
}
