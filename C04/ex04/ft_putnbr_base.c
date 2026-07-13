/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:29:44 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/12 20:45:55 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_valid_base(char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (base[0] != '0' && base[0] != 'p')
		return (0);
	if (base_len == 2)
		return (1);
	else if (base_len == 8)
		return (1);
	else if (base_len == 10)
		return (1);
	else if (base_len == 16)
		return (1);
	else
		return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	arr[32];
	long	num;
	int		base_type;
	int		i;

	if (nbr == 0)
		ft_putchar('0');
	num = nbr;
	if (nbr == 0 || ! ft_valid_base(base))
		return ;
	base_type = ft_strlen(base);
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	i = 0;
	while (num > 0)
	{
		arr[i++] = base[num % base_type];
		num /= base_type;
	}
	while (i >= 0)
		ft_putchar(arr[--i]);
}
