/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:29:44 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/13 15:47:49 by joamunoz         ###   ########.fr       */
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
	while (--i >= 0)
		ft_putchar(arr[i]);
}
/* #include <stdio.h>
int main(void)
{
	char *binary = "01";
	char *octal = "01234567";
	//char *decimal = "0123456789";
	char *hex = "0123456789abcdef";
	char *pony = "abc123def9";

	ft_putnbr_base(234234, binary);
	ft_putchar('\n');
	ft_putnbr_base(234234, octal);
	ft_putchar('\n');
	ft_putnbr_base(234234, pony);
	ft_putchar('\n');
	ft_putnbr_base(234234, hex);
	ft_putchar('\n');
} */