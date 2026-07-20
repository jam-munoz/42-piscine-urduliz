/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:12:23 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/20 14:12:52 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_print_header(char *argv, int i)
{
	if (i == 3)
		ft_putstr("==> ");
	else
		ft_putstr("\n==> ");
	ft_putstr(argv);
	ft_putstr(" <==\n");
}
