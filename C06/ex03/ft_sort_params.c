/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:51:55 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/11 17:36:42 by joamunoz         ###   ########.fr       */
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
	write(1, "\n", 1);
}

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

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	*lowest;
	int	temp;
	int	sorted;
	int	i;

	if (size < 1)
		return ;
	lowest = &tab[0];
	sorted = 0;
	while (sorted < size)
	{
		lowest = &tab[sorted];
		i = sorted + 1;
		while (i < size)
		{
			if (*lowest > tab[i])
				lowest = &tab[i];
			i++;
		}
		temp = tab[sorted];
		tab[sorted] = *lowest;
		*lowest = temp;
		sorted++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	unsorted;

	i = 2;
	unsorted = 1;
	while (unsorted)
	{
		unsorted = 0;
		i = 2;
		while (i < argc)
		{
			if (ft_strcmp(argv[i - 1], argv[i]) > 0)
			{
				ft_swap(&argv[i - 1], &argv[i]);
				unsorted = 1;
			}
			i++;
		}
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
