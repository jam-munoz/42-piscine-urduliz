#include <stdio.h>
#include <stdlib.h>

int ft_sep(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return 1;
	else
		return 0;
}
char *ft_word_split(char *str)
{
	int i = 0;
	int len = 0;
	char *word;
	while (str[len] && !ft_sep(str[len]))
	{
		len++;
	}
	word = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return word;
}
char **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int len = 0;
	int words = 0;
	char **out;
	char *p;

	while (str[len])
	{
		if (!ft_sep(str[len]))
		{
			words++;
			while (!ft_sep(str[len]))
				len++;
		}
		else
			len++;
	}
	out = malloc((words + 1) * sizeof(char *));
	if (!out)
	{
		free(out);
		return NULL;
	}
	while (i < words)
	{
		while (ft_sep(str[j]))
		{
			j++;
		}
		out[i] = ft_word_split(&str[j]);
		while (str[j] && !ft_sep(str[j]))
		{
			j++;
		}
		i++;
	}
	out[i] = NULL;
	return out;
}

int main(void)
{
	int i = 0;
	char **arr;
	char *str = "las papas s. a. ";
	arr = ft_split(str);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	free(arr);
	return 0;
}