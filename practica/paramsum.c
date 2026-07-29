/* Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>*/

#include <unistd.h>

void	ft_putnbr(int nb);
void ft_putchar(char c);

int main(int argc, char *argv[])
{
    ft_putnbr(argc - 1);
    ft_putchar('\n');
    (void)argv;
    return 0;
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

void ft_putchar(char c)
{
    write(1, &c, 1);
}