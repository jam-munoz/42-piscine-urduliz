/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:39:36 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/12 20:20:37 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char *ft_str_create(int size, char **strs, char *sep)
{
	char	*str;
	int	len;
	int	i;
	int	strnum;

	len = 0;
	i = 0;
	strnum = 0;
	if (size < 1)
		len = 1;
	else
	{
		while (strnum < size)
		{
			while (strs[strnum][i++])
				len++;
			i = 0;
			strnum++;
		}
	}
	len += ft_strlen(sep) * size - 1;
	str = malloc(len * sizeof(char));
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *str;
	int	i;
	int	strnum;
	int	len;

	str = ft_str_create(size, strs, sep);
	strnum = 0;
	len = 0;
	if (size == 0)
	{
		str[len] = '\0';
		return(str);
	}
	while (strnum < size)
	{
		i = 0;
		while (strs[strnum][i])
			str[len++] = strs[strnum][i++];
		i = 0;
		while (sep[i] && strnum < (size - 1))
			str[len++] = sep[i++];
		strnum++;
	}
	str[len] = '\0';
	return (str);
}
