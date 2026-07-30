/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:44:02 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/14 17:38:26 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_str_is_numeric(char *str)
{
	int	len;
	int	i;

	if (!str)
		return (1);
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (!('0' <= str[i] && str [i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
