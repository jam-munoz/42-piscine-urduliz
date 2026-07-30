#include <unistd.h>
void	ft_putchar(char c);
int	ft_strlen(char *str);

int is_pal(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return 0;
		start++;
		end--;
	}
	return 1;
}

void print_sub(char *str, int start, int end)
{
	while (start <= end)
	{
		ft_putchar(str[start]);
		start++;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	char *str = argv[1];

	int best_start = 0;
	int best_end = -1;
	int best_len = 0;

	int i = 0;
	int len = ft_strlen(str);
	int k;
	while (i < len)
	{
		k = i;
		while (k < len)
		{
			if (is_pal(str, i, k) && (k - i + 1) >= best_len)
			{
				best_start = i;
				best_end = k;
				best_len = k - i + 1;
			}
			k++;
		}
		i++;
	}

	print_sub(str, best_start, best_end);
	ft_putchar('\n');
	return
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
