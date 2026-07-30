/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 19:14:52 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/07 19:52:12 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
