/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:12:23 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/23 10:12:57 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_print_header(char *argv, int i)
{
	if (i == 3)
		ft_putstr("==> ", 1);
	else
		ft_putstr("\n==> ", 1);
	ft_putstr(argv, 1);
	ft_putstr(" <==\n", 1);
}
