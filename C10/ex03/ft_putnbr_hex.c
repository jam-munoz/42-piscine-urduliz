/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:29:44 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/20 18:46:56 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

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

void	ft_putnbr_hex(int num)
{
	char	arr[32];
	char	base[17];
	int		i;

	ft_strcpy(base, "0123456789abcdef");
	if (num == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	if (num < 16)
		ft_putchar('0');
	i = 0;
	while (num > 0)
	{
		arr[i++] = base[num % 16];
		num /= 16;
	}
	while (--i >= 0)
		ft_putchar(arr[i]);
}
