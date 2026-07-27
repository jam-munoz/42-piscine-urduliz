/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/27 23:49:59 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_print_str(int output, char *str)
{
	while (*str)
		write(output, str++, 1);
	return ;
}
