/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 21:24:53 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/22 11:07:27 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	is_alpha;
	int	len;
	int	i;

	is_alpha = 1;
	len = 0;
	i = 0;
	if (!str)
		return (is_alpha);
	while (str[len])
		len++;
	while (i < len)
	{
		if (!(('A' <= str[i] && str [i] <= 'Z')
				|| ('a' <= str[i] && str[i] <= 'z')))
		{
			is_alpha = 0;
			return (is_alpha);
		}
		i++;
	}
	return (is_alpha);
}
