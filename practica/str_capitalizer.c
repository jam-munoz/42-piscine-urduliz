/* Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>*/

#include <unistd.h>

void    ft_putchar(char c);
int ft_sep(char c);
int ft_is_lower(char c);
int ft_is_upper(char c);

int main(int argc, char *argv[])
{
    if (argc < 2 || !argv[1])
    {
        ft_putchar('\n');
        return 0;
    }

    int i = 1;
    int k;
    int first;

    while(i < argc)
    {
        k = 0;
        first = 1;
        while(argv[i][k])
        {
            if (first && ft_is_lower(argv[i][k]))
                ft_putchar(argv[i][k] - 32);
            else if (!first && ft_is_upper(argv[i][k]))
                ft_putchar(argv[i][k] + 32);
            else
                ft_putchar(argv[i][k]);
            first = 0;
            if (ft_sep(argv[i][k]))
                first = 1;
            k++;
        }
        ft_putchar('\n');
        i++;
    }
    ft_putchar('\n');
}

int ft_is_lower(char c)
{
    if ('a' <= c && c <= 'z')
        return 1;
    else
        return 0;
}

int ft_is_upper(char c)
{
    if ('A' <= c && c <= 'Z')
        return 1;
    else
        return 0;
}

int ft_sep(char c)
{
    if (c == ' ' || (9 <= c && c <= 13) || !c)
        return 1;
    else
        return 0;
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
