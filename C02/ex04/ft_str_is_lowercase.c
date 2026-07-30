/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:46:24 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/08 13:21:05 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	is_lowercase;
	int	len;
	int	i;

	is_lowercase = 1;
	len = 0;
	i = 0;
	if (!str)
		return (is_lowercase);
	while (str[len])
		len++;
	while (i < len)
	{
		if (!('a' <= str[i] && str[i] <= 'z'))
		{
			is_lowercase = 0;
			return (is_lowercase);
		}
		i++;
	}
	return (is_lowercase);
}
