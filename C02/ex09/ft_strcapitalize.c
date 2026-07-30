/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 11:33:58 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/26 17:30:33 by joamunoz         ###   ########.fr       */
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

int	ft_is_alpha(char *ch)
{
	if (('A' <= *ch && *ch <= 'Z') || ('a' <= *ch && *ch <= 'z'))
		return (1);
	else
		return (0);
}

int	ft_is_num(char *ch)
{
	if ('0' <= *ch && *ch <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	len;
	int	i;
	int	first_letter;

	first_letter = 1;
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		while (('A' <= str[i] && str[i] <= 'Z')
			|| ('a' <= str[i] && str[i] <= 'z'))
		{
			if (first_letter && 'a' <= str[i] && str[i] <= 'z')
				str[i] -= ('a' - 'A');
			if (!first_letter && ('A' <= str[i] && str[i] <= 'Z'))
				str[i] += ('a' - 'A');
			first_letter = 0;
			i++;
		}
		first_letter = 0;
		if (! (ft_is_alpha(&str[i]) || ft_is_num(&str[i])))
			first_letter = 1;
		i++;
	}
	return (str);
}
