/* Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/

#include <unistd.h>
int	ft_atoi(const char *str);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void    ft_putchar(char c);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        ft_putchar('\n');
        return 0;
    }
    int n = ft_atoi(argv[1]);
    int i = 1;
    while (i < 10)
    {
        ft_putnbr(i);
        ft_putstr(" x ");
        ft_putnbr(n);
        ft_putstr(" = ");
        ft_putnbr(i * n);
        ft_putchar('\n');
        i++;
    }
}

int	ft_atoi(const char *str)
{
    int i = 0;
    int sum = 0;
    int sign = 1;
    while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while ('0' <= str[i] && str[i] <= '9')
    {
        sum *= 10;
        sum += str[i] - '0';
        i++;
    }
    return (sign * sum);
}

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb == -2147483647 - 1)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
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

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
