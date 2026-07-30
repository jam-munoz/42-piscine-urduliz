/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcosio <mcosio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 18:30:49 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/26 23:20:34 by mcosio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# define HUNDRED 28
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_count_words(char *str);
int		ft_check_errors(int argc);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_ones(char **dict, int *i, int argc, char *argv[]);
void	ft_print_tens(char **dict, int *i, int argc, char *argv[]);
void	ft_print_hundreds(char **dict, int *i, int argc, char *argv[]);
void	ft_print_thousands(char **dict, int *i, int argc, char *argv[]);
void	ft_print_ten_thousands(char **dict, int *i, int argc, char *argv[]);
void	ft_print_hundred_thousands(char **dict, int *i, int argc, char *argv[]);
void	ft_print_million(char **dict, int *i, int argc, char *argv[]);
void	ft_print_ten_million(char **dict, int *i, int argc, char *argv[]);
void	ft_print_hundred_million(char **dict, int *i, int argc, char *argv[]);
void	ft_print_numbers(char **dict, int argc, char *argv[]);

#endif
