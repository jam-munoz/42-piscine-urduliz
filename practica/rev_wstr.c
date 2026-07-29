/* Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>*/

#include <unistd.h>

void    ft_putchar(char c);
void	ft_putstr(char *str);
int ft_sep(char c);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        ft_putchar('\n');
        return 0;
    }
    int i = 0;
    char *str = argv[1];
    while (str[i])
        i++;
    while (i >= 0)
    {
        while(i >= 0 && !ft_sep(str[i]))
            i--;
        ft_putstr(&str[i+1]);
        while(i >= 0 && ft_sep(str[i]))
            i--;
        if (i >= 0)
            ft_putchar(' ');
    }
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