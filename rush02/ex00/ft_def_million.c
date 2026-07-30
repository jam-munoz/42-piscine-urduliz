/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def_million.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcosio <mcosio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:22:30 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/26 23:19:05 by mcosio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_print_hundred_thousands(char **dict, int *i, int argc, char *argv[])
{
	ft_print_hundreds(dict, i, argc, argv);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED +1]);
	ft_putchar(' ');
	ft_print_hundreds(dict, i, argc, argv);
}

void	ft_print_million(char **dict, int *i, int argc, char *argv[])
{
	ft_print_ones(dict, i, argc, argv);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED +2]);
	ft_putchar(' ');
	ft_print_hundreds(dict, i, argc, argv);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED +1]);
	ft_putchar(' ');
	ft_print_hundreds(dict, i, argc, argv);
}

void	ft_print_ten_million(char **dict, int *i, int argc, char *argv[])
{
	ft_print_tens(dict, i, argc, argv);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED +2]);
	ft_putchar(' ');
	ft_print_hundreds(dict, i, argc, argv);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED +1]);
	ft_putchar(' ');
	ft_print_hundreds(dict, i, argc, argv);
}

void	ft_print_hundred_million(char **dict, int *i, int argc, char *argv[])
{
	ft_print_hundreds(dict, i, argc, argv);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED +2]);
	ft_putchar(' ');
	ft_print_hundreds(dict, i, argc, argv);
	ft_putchar(' ');
	ft_putstr(dict[HUNDRED +1]);
	ft_putchar(' ');
	ft_print_hundreds(dict, i, argc, argv);
}
