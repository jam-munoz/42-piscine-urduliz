/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:36:37 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/12 18:12:45 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}
int ft_word_count(char *str, char *charset)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		if (! ft_is_sep(str[i], charset))
		{
			word_count++;
			while (str[i] && (! ft_is_sep(str[i], charset)))
				i++;
		}
		else
			i++;
	}
	return (word_count);
}
char *ft_word_split(char *str, char *charset)
{
	char *word;
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[len] && ! ft_is_sep(str[len], charset))
		len++;
	word = malloc((len + 1) * sizeof(char *));
	if (word == NULL)
		return (NULL);
	while (str[i] && ! ft_is_sep(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split(char *str, char *charset)
{
	char **arr;
	int	i;
	int	len;

	i = 0;
	len = 0;
	arr = malloc(((ft_word_count(str, charset) + 1) * sizeof(char *)));
	if (arr == NULL || str == NULL || charset == NULL)
		return (NULL);
	while (str[len])
	{
		if (! ft_is_sep(str[len], charset))
		{
			arr[i] = ft_word_split(&str[len], charset);
			while (str[len] && !ft_is_sep(str[len], charset))
				len++;
			i++;
		}
		else
			len++;
	}
	arr[i] = '\0';
	return (arr);
}
