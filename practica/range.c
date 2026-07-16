#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
	int *out;
	int i = 0;
	if (start > end)
		return NULL;
	int dif = (end - start);
	out = malloc((dif + 1) * sizeof(int));
	if (!out)
	{
		free(out);
		return NULL;
	}
	while (start <= end)
	{
		out[i] = start;
		start++;
		i++;
	}
	return out;
}

int main(void)
{
	int i = 0;
	int x = 0;
	int y = 10;
	int *range;
	range = ft_range(x, y);
	while(i < ((y - x)+1))
	{
		printf("%d\n", range[i]);
		i++;
	}
	free(range);
	return 0;
}