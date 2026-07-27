/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:28:50 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/27 23:47:04 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_atoi(char *str);
void	ft_print_fd(int fd, int bytes);
int		ft_print_file(char *name, char *str, int bytes, int file_i);
void	ft_print_str(int output, char *str);
int		ft_read_count(int argc, char **argv);
int		ft_strcmp(char *a, char *b);

#endif
