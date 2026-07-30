typedef struct s_point
{
	int x;
	int y;
}	t_point;

void flood_util(char **tab, t_point size, t_point begin, char target)
{
	t_point next;
	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return;
	if (tab[begin.y][begin.x] != target)
		return;
	tab[begin.y][begin.x] = 'F';
	next.x = begin.x + 1;
	next.y = begin.y;
	flood_util(tab, size, next, target);
	next.x = begin.x - 1;
	next.y = begin.y;
	flood_util(tab, size, next, target);
	next.x = begin.x;
	next.y = begin.y + 1;
	flood_util(tab, size, next, target);
	next.x = begin.x;
	next.y = begin.y - 1;
	flood_util(tab, size, next, target);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	flood_util(tab, size, begin, tab[begin.y][begin.x]);
}

#include <stdio.h>
#include <stdlib.h>

char **make_area(char **zone, t_point size)
{
	char **new;

	new = malloc(size.y * sizeof(char *));
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
		{
			new[i][j] = zone[i][j];
		}
		new[i][size.x] = '\0';
	}
	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char **area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
	{
		printf("%s\n", area[i]);
	}
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return 0;
}