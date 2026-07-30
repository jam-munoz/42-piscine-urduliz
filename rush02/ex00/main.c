/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:49:50 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/30 11:52:21 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_word_split(char *str)
{
	int		i;
	int		len;
	char	*out;

	i = 0;
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		len++;
	}
	i = 0;
	out = malloc((len + 1) * sizeof(char));
	if (!out)
	{
		free(out);
		return (NULL);
	}
	while (i < len)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	**ft_split(char *str)
{
	int		i;
	int		k;
	int		words;
	char	**out;

	i = 0;
	k = 0;
	words = ft_count_words(str);
	out = malloc((words + 1) * sizeof(char *));
	if (!out)
		free(out);
	if (!out)
		return (NULL);
	while (k < words)
	{
		while (str[i] != ':')
			i++;
		i++;
		while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
			i++;
		out[k] = ft_word_split(&str[i]);
		k++;
	}
	out[k] = NULL;
	return (out);
}

char	*assign_file(int argc, char *argv[])
{
	char	*file;

	if (argc == 2)
		file = "numbers.dict";
	if (argc == 3)
		file = argv[1];
	return (file);
}

char	**read_file(int argc, char *argv[])
{
	char	*file;
	char	*buf;
	char	**arr;
	int		fd;
	int		bytes_read;

	file = assign_file(argc, argv);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (NULL);
	}
	buf = malloc(10000);
	bytes_read = read(fd, buf, 10000);
	while (bytes_read > 0)
		bytes_read = read(fd, buf, 10000);
	arr = ft_split(buf);
	close(fd);
	free(buf);
	return (arr);
}

int	main(int argc, char *argv[])
{
	char	**dict;
	int		i;

	i = 0;
	if (ft_check_errors(argc))
		return (1);
	dict = read_file(argc, argv);
	if (dict == NULL)
		return (0);
	ft_print_numbers(dict, argc, argv);
	ft_putchar('\n');
	while (dict[i])
		free (dict[i++]);
	free(dict);
	return (0);
}
