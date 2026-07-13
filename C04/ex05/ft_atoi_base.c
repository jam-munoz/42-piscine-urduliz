/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 19:31:16 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/13 17:55:40 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int	ft_valid_number(char c, char *base)
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
	while (ft_valid_number(str[i], base) != (-1))
	{
		sum *= base_type;
		sum += ft_valid_number(str[i], base);
		i++;
	}
	return (sign * sum);
}

/* #include <stdio.h>
int main(void)
{
	char *binary = "01";
	char *octal = "01234567";
	char *decimal = "0123456789";
	char *hex = "0123456789abcdef";

	char *a = "1111101000";
	char *b = "1750";
	char *c = "   ---+-+1000ab567";
	char *d = "3e8";

	printf("binario: %d\noctal: %d\ndecimal: %d\nhex: %d\n",
	ft_atoi_base(a, binary), ft_atoi_base(b, octal),
	ft_atoi_base(c, decimal), ft_atoi_base(d, hex));
} */
