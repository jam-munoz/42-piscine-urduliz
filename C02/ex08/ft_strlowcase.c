/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 11:33:04 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/08 13:21:17 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!str)
		return (str);
	while (str[len])
		len++;
	while (i < len)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		i++;
	}
	return (str);
}
