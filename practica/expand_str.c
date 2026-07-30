#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int is_sep(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return 1;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	char *str = argv[1];
	int i = 0;
	while(is_sep(str[i]) && str[i])
	{
		i++;
	}
	while (str[i])
	{
		if(!is_sep(str[i]))
		{
			ft_putchar(str[i]);
		}
		else
			ft_putstr("   ");
		i++;
	}
	ft_putchar('\n');
}