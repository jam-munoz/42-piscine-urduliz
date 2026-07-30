/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:22:30 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/26 21:04:24 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

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

int	ft_check_errors(int argc)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	else
		return (0);
}

int	ft_count_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == ':')
			words++;
		i++;
	}
	return (words);
}
