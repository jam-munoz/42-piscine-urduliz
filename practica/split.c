#include <stdlib.h>

int is_sep(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
	{
		return 1;
	}
	else
		return 0;
}

char *word_split(char *str)
{
	int len = 0;
	int j = 0;
	char *out;
	while (str[len] && !is_sep(str[len]))
		len++;
	out = malloc((len + 1) * sizeof(char));
	while (j < len)
	{
		out[j] = str[j];
		j++;
	}
	out[j] = '\0';
	return out;
}

char **ft_split(char *str)
{
	int i = 0;
	int words = 0;
	while (str[i])
	{
		if (!is_sep(str[i]))
		{
			words++;
			while(str[i] && !is_sep(str[i]))
				i++;
		}
		else
			i++;
	}
	char **out = malloc((words + 1) * sizeof(char *));
	if (!out)
	{
		free(out);
		return NULL;
	}
	i = 0;
	int j = 0;
	while (j < words)
	{
		while (is_sep(str[i]))
			i++;
		out[j] = word_split(&str[i]);
		while (str[i] && !is_sep(str[i]))
			i++;
		j++;
	}
	out[j] = NULL;
	return out;
}

#include <stdio.h>
int main(void)
{
	int i;
	char *str = "las papas s. a.";
	char **split = ft_split(str);
	for (i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	for (i = 0; split[i]; i++)
		free(split[i]);
	free(split);
	return 0;
}