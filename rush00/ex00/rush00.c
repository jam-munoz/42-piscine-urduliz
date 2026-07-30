/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:14:46 by usan-jos          #+#    #+#             */
/*   Updated: 2026/07/30 11:45:13 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first_line(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
		col++;
	}
}

void	ft_body(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
		col++;
	}
}

void	rush(int x, int y)
{
	int	row;

	if (x < 1 || y < 1)
		return ;
	row = 0;
	while (row < y)
	{
		if (row == 0 || row == y - 1)
			ft_first_line(x);
		else
			ft_body(x);
		ft_putchar('\n');
		row++;
	}
}
