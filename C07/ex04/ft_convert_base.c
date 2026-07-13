/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:31:51 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/13 20:07:11 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_digit_count(int num, char *base);

void	ft_putnbr_base(int nbr, char *base, char *out);

int	ft_clean_space(char *str, int *s)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*s = sign;
	return (i);
}

int	ft_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] <= 32 || base[i] > 126
			|| base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_sum_number(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	sum;
	int	base_type;

	if (! ft_valid_base(base))
		return (0);
	sum = 0;
	base_type = ft_valid_base(base);
	if (base_type < 2)
		return (0);
	i = ft_clean_space(str, &sign);
	while (ft_sum_number(str[i], base) != (-1))
	{
		sum *= base_type;
		sum += ft_sum_number(str[i], base);
		i++;
	}
	return (sign * sum);
}
char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n;
	int	i;
	char *convert;
	
	if (!ft_valid_base(base_from) || !ft_valid_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	i = ft_digit_count(n, base_to);
	convert = malloc((i + 1) * sizeof(char));
	ft_putnbr_base(n, base_to, convert);
	convert[i] = '\0';
	return (convert);
}
