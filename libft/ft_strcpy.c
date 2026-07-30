/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 21:11:21 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/08 13:55:04 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
