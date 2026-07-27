/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:26:31 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/27 23:49:52 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_error_missing_arg(char *name)
{
	ft_print_str(2, name);
	ft_print_str(2, ": option requires an argument -- 'c'\nTry '");
	ft_print_str(2, name);
	ft_print_str(2, " --help' for more information.\n");
	return (-2);
}

int	ft_error_nbytes(char *name, char *arg)
{
	ft_print_str(2, name);
	ft_print_str(2, ": invalid number of bytes: ‘");
	ft_print_str(2, arg);
	ft_print_str(2, "’\n");
	return (-2);
}

int	ft_read_count(int argc, char **argv)
{
	int	i;
	int	count;

	i = -1;
	count = -1;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-c") == 0)
		{
			if (i == argc - 1)
				return (ft_error_missing_arg(argv[0]));
			else
			{
				count = ft_atoi(argv[i + 1]);
				if (count < 0)
					return (ft_error_nbytes(argv[0], argv[i + 1]));
			}
			argv[i] = NULL;
			i++;
			argv[i] = NULL;
		}
	}
	return (count);
}
