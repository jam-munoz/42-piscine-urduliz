/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:48:01 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/08 13:21:09 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	is_uppercase;
	int	len;
	int	i;

	is_uppercase = 1;
	len = 0;
	i = 0;
	if (!str)
		return (is_uppercase);
	while (str[len])
		len++;
	while (i < len)
	{
		if (!('A' <= str[i] && str [i] <= 'Z'))
		{
			is_uppercase = 0;
			return (is_uppercase);
		}
		i++;
	}
	return (is_uppercase);
}
