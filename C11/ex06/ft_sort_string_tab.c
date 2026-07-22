/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:51:29 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/21 15:32:43 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	unsorted;
	int	len;

	i = 1;
	unsorted = 1;
	len = ft_strlen(tab);
	while (unsorted)
	{
		unsorted = 0;
		i = 1;
		while (i < len)
		{
			if (ft_strcmp(tab[i - 1], tab[i]) > 0)
			{
				ft_swap(&tab[i - 1], &tab[i]);
				unsorted = 1;
			}
			i++;
		}
	}
}

/* #include <stdlib.h>
#include <stdio.h>
int main(void)
{
	char *str[] = { "hi", "01ok", "NO", NULL };
	ft_sort_string_tab(str);
	for (int i = 0; str[i]; i++)
	{
		printf("%s\n", str[i]);
	}
} */
