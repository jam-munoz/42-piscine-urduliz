/* Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>*/

#include <unistd.h>

void    ft_putchar(char c);
void	ft_putstr(char *str);
int ft_sep(char c);

int main(int argc, char *argv[])
{
    if (argc < 2 || !argv[1])
    {
        ft_putchar('\n');
        return 0;
    }
    int i = 0;
    int len = 0;
    char *str = argv[1];
    while (str[len])
        len++;
    while (ft_sep(str[i]))
        i++;
    while (!ft_sep(str[i]))
        i++;
    while (i < len)
    {
        while (ft_sep(str[i]))
            i++;
        if (i < len)
        {
            ft_putstr(&str[i]);
            ft_putchar(' ');
        }
        while (i < len && !ft_sep(str[i]))
            i++;
    }
    i = 0;
    while (ft_sep(str[i]))
        i++;
    ft_putstr(&str[i]);
    ft_putchar('\n');
}

int ft_sep(char c)
{
    if (c == ' ' || (9 <= c && c <= 13))
        return 1;
    else
        return 0;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !ft_sep(str[i]))
	{
		write(1, &str[i], 1);
		i++;
	}
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}