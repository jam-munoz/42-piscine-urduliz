/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 19:31:16 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/12 20:47:13 by joamunoz         ###   ########.fr       */
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

int	ft_is_number(char c, int base)
{
	if (base == 2 && ('0' <= c && c <= '1'))
		return (1);
	else if (base == 8 && ('0' <= c && c <= '7'))
		return (1);
	else if (base == 10 && ('0' <= c && c <= '9'))
		return (1);
	else if (base == 16 && (('0' <= c && c <= '9')
			|| ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F')))
		return (1);
	else
		return (0);
}

void	ft_add_hex(int *nbr, char c)
{
	if ('a' <= c && c <= 'f')
		*nbr += (c - 'a' + 10);
	else if ('A' <= c && c <= 'F')
		*nbr += (c - 'A' + 10);
	else if ('0' <= c && c <= '9')
		*nbr += (c - '0');
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	sum;
	int	base_type;

	if (! ft_valid_base(base))
		return (0);
	i = 0;
	sign = 1;
	sum = 0;
	base_type = ft_strlen(base);
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_is_number(str[i], base_type))
	{
		sum *= base_type;
		if (base_type == 16)
			ft_add_hex(&sum, str[i++]);
		else
			sum += (str[i++] - '0');
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
