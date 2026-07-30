/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:44:02 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/08 13:21:03 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	is_numeric;
	int	len;
	int	i;

	is_numeric = 1;
	len = 0;
	i = 0;
	if (!str)
		return (is_numeric);
	while (str[len])
		len++;
	while (i < len)
	{
		if (!('0' <= str[i] && str [i] <= '9'))
		{
			is_numeric = 0;
			return (is_numeric);
		}
		i++;
	}
	return (is_numeric);
}
