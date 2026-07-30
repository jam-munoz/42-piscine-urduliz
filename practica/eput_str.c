#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
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
	if (argc != 2 || !argv[1][0])
	{
		ft_putchar('\n');
		return 0;
	}
	int i = 0;
	int first_word = 1;
	char *s = argv[1];
	while(s[i])
	{
		if(!is_sep(s[i]))
		{
			if(!first_word)
				ft_putchar(' ');
			while(s[i] && !is_sep(s[i]))
			{

				ft_putchar(s[i]);
				i++;
			}
			first_word = 0;
		}
		else
			i++;
	}
	ft_putchar('\n');
}