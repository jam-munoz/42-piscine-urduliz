/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:32:07 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/13 20:07:21 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int	ft_digit_count(int num, char *base)
{
	int	i;
	int	base_type;
	long	n;

	i = 0;
	base_type = ft_strlen(base);
	n = num;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= base_type)
	{
		n /= base_type;
		i++;
	}
	i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base, char *out)
{
	long	num;
	int		base_type;
	int		start;
	int		i;

	num = nbr;
	base_type = ft_strlen(base);
	start = 0;
	i = ft_digit_count(nbr, base);
	if (num < 0)
	{
		out[0] = '-';
		num *= -1;
		start++;
	}
	i--;
	while (num >= base_type)
	{
		out[i--] = base[num % base_type];
		num /= base_type;
	}
	if (num < base_type)
	{
		out[start] = base[num];
	}
}
