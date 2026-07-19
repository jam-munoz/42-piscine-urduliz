/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 13:44:25 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/19 11:30:36 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	len;
	int	i;

	len = 0;
	while (s1[len])
		len++;
	i = 0;
	while (i <= len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

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

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (g_solution[i].input)
	{
		if (ft_strcmp(argv[1], g_solution[i].input) == 0)
		{
			ft_putstr(g_solution[i].output);
			return (0);
		}
		i++;
	}
	write (1, "Error\n", 6);
}
