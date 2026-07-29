/* Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
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
    while (i < argc)
    {
        k = 0;
        while(argv[i][k])
        {
            if (ft_is_lower(argv[i][k]) && ft_sep(argv[i][k+1]))
                ft_putchar((argv[i][k]) - 32);
            else if (ft_is_upper(argv[i][k]) && !ft_sep(argv[i][k+1]))
                ft_putchar((argv[i][k]) + 32);
            else
                ft_putchar(argv[i][k]);
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
