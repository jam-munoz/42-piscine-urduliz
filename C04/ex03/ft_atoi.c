/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:26:52 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/12 19:30:08 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	sum;

	i = 0;
	sign = 1;
	sum = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		sum *= 10;
		sum += (str[i] - '0');
		i++;
	}
	return (sign * sum);
}

/*#include <stdio.h>
int main(void)
{
//	char *str = "    ---+--+1234ab567";
	char *str = "-1325632167";
	int prueba = ft_atoi(str);
	printf("%d\n", prueba);
}*/