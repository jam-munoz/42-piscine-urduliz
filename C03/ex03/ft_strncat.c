/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:04:12 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/08 16:58:33 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				start;

	i = 0;
	start = 0;
	while (dest[start])
		start++;
	while (src[i] && i < nb)
	{
		dest[start] = src[i];
		start++;
		i++;
	}
	dest[start] = '\0';
	return (dest);
}
