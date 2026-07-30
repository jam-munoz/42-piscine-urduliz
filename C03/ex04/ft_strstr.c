/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:08:50 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/21 16:45:22 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	find;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		find = 0;
		while (str[i + find] && str[i + find] == to_find[find])
		{
			if (!to_find[find + 1])
				return (&str[i]);
			find++;
		}
		i++;
	}
	return (0);
}
/* #include <stdio.h>

int	main(void)
{
	char	to_find[] = { '\0' };
	char	string[] = "pifffounfoundpan";
	char	*to_print;

	to_print = ft_strstr(string, to_find);
	printf("%s",to_print);
	return (0);
} */