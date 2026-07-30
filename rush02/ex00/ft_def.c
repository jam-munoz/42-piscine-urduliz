/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:22:30 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/26 21:04:24 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_print_ones(char **dict, int *i, int argc, char *argv[])
{
	int	n;

	n = argv[argc - 1][*i] - '0';
	ft_putstr(dict[n]);
	*i = *i + 1;
	return ;
}

void	ft_print_tens(char **dict, int *i, int argc, char *argv[])
{
	int	n;
	int	k;
	int	ones;

	n = argv[argc - 1][*i] - '0';
	k = argv[argc - 1][*i + 1] - '0';
	ones = 1;
	if (n == 1)
	{
		n = (n * 10) + k;
		ft_putstr(dict[n]);
		ones = 0;
	}
	else if (n != 0)
	{
		ft_putstr(dict[n + 18]);
		ft_putchar(' ');
	}
	*i = *i + 1;
	if (ones)
		ft_print_ones(dict, i, argc, argv);
}

void	ft_print_hundreds(char **dict, int *i, int argc, char *argv[])
{
	int	n;

	n = argv[argc - 1][*i] - '0';
	if (n != 0)
		ft_putstr(dict[n]);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED]);
	ft_putchar(' ');
	*i = *i + 1;
	ft_print_tens(dict, i, argc, argv);
}

void	ft_print_thousands(char **dict, int *i, int argc, char *argv[])
{
	ft_print_ones(dict, i, argc, argv);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED +1]);
	ft_putchar(' ');
	ft_print_hundreds(dict, i, argc, argv);
}

void	ft_print_ten_thousands(char **dict, int *i, int argc, char *argv[])
{
	ft_print_tens(dict, i, argc, argv);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED +1]);
	ft_putchar(' ');
	ft_print_hundreds(dict, i, argc, argv);
}
