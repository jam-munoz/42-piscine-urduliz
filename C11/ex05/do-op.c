/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 11:08:33 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/21 15:46:15 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ADDITION 0
#define SUBSTRACTION 1
#define MULTIPLICATION 2
#define DIVISION 3
#define MODULUS 4

#include <unistd.h>

int	ft_addition(int x, int y);
int	ft_substraction(int x, int y);
int	ft_multiplication(int x, int y);
int	ft_division(int x, int y);
int	ft_modulus(int x, int y);
int	ft_atoi(char *str);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_div_zero(int operand, int y)
{
	if (y == 0 && operand == DIVISION)
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	if (y == 0 && operand == MODULUS)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	if (operand == -1)
	{
		ft_putstr("0\n");
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb == -2147483647 -1)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
}

int	ft_check_operand(char *sign)
{
	if (sign[1])
		return (-1);
	if (sign[0] == '+')
		return (ADDITION);
	else if (sign[0] == '-')
		return (SUBSTRACTION);
	else if (sign[0] == '*')
		return (MULTIPLICATION);
	else if (sign[0] == '/')
		return (DIVISION);
	else if (sign[0] == '%')
		return (MODULUS);
	return (-1);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;
	int	operand;
	int	result;
	int	(*fptr[5])(int x, int y);

	fptr[ADDITION] = &ft_addition;
	fptr[SUBSTRACTION] = &ft_substraction;
	fptr[MULTIPLICATION] = &ft_multiplication;
	fptr[DIVISION] = &ft_division;
	fptr[MODULUS] = &ft_modulus;
	operand = ft_check_operand(argv[2]);
	if (argc != 4)
		return (1);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	if (ft_div_zero(operand, y))
		return (1);
	result = fptr[operand](x, y);
	ft_putnbr(result);
	ft_putstr("\n");
	return (0);
}
