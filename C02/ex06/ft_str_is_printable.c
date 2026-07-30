/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:50:45 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/08 13:21:13 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	is_printable;
	int	len;
	int	i;

	is_printable = 1;
	len = 0;
	i = 0;
	if (!str)
		return (is_printable);
	while (str[len])
		len++;
	while (i < len)
	{
		if (!(' ' <= str[i] && str [i] <= '~'))
		{
			is_printable = 0;
			return (is_printable);
		}
		i++;
	}
	return (is_printable);
}
