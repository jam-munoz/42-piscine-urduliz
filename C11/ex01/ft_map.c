/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 20:29:40 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/21 19:27:31 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*out;
	int	i;

	i = 0;
	out = malloc(length * sizeof(int));
	if (!out)
	{
		return (NULL);
	}
	while (i < length)
	{
		out[i] = f(tab[i]);
		i++;
	}
	return (out);
}
