/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:15:04 by usan-jos          #+#    #+#             */
/*   Updated: 2026/07/30 11:45:32 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first_line(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar('A');
		else if (col == x -1)
			ft_putchar('C');
		else
			ft_putchar('B');
		col++;
	}
}

void	ft_end_line(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar('C');
		else if (col == x -1)
			ft_putchar('A');
		else
			ft_putchar('B');
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
			ft_putchar('B');
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
		if (row == 0)
			ft_first_line(x);
		else if (row == y - 1)
			ft_end_line(x);
		else
			ft_body(x);
		ft_putchar('\n');
		row++;
	}
}
