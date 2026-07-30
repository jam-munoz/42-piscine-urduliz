/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcosio <mcosio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:27:13 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/26 23:20:01 by mcosio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_print_numbers(char **dict, int argc, char *argv[])
{
	int	*i;
	int	j;
	int	len;

	i = &j;
	*i = 0;
	len = ft_strlen(argv[argc - 1]);
	if (len == 1)
		ft_print_ones(dict, i, argc, argv);
	if (len == 2)
		ft_print_tens(dict, i, argc, argv);
	if (len == 3)
		ft_print_hundreds(dict, i, argc, argv);
	if (len == 4)
		ft_print_thousands(dict, i, argc, argv);
	if (len == 5)
		ft_print_ten_thousands(dict, i, argc, argv);
	if (len == 6)
		ft_print_hundred_thousands(dict, i, argc, argv);
	if (len == 7)
		ft_print_million(dict, i, argc, argv);
	if (len == 8)
		ft_print_ten_million(dict, i, argc, argv);
	if (len == 9)
		ft_print_hundred_million(dict, i, argc, argv);
}
