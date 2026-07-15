/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:25:06 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/14 18:26:20 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dup;

	len = ft_strlen(src);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*array;

	array = malloc((ac + 1) * sizeof(t_stock_str));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (NULL);
		array[i].size = ft_strlen(av[i]);
		array[i].str = ft_strdup(av[i]);
		array[i].copy = ft_strdup(av[i]);
		if (array[i].str == NULL || array[i].copy == NULL)
			return (NULL);
		i++;
	}
	array[i].str = NULL;
	return (array);
}

/* #include <stdio.h>
int main(void)
{
	t_stock_str *converted;
	char *strings[4] = { "hola", "hi", "salut", "ciao" };
	int size = 4;
	int i = 0;
	converted = ft_strs_to_tab(size, strings);
	while (i < size)
	{
		printf("size: %d, str: %s, copy: %s\n",
			converted[i].size, converted[i].str, converted[i].copy);
		i++;
	}
	free(converted);
	return 0;
} */