/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:39:26 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/28 18:51:55 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_map
{
	char	**grid;
	int		cols;
	int		rows;
	char	empty;
	char	full;
	char	obstacle;
}	t_map;

#endif