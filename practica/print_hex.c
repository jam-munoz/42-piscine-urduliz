/* Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$*/

#include <unistd.h>

int	ft_atoi(const char *str);
void ft_putnbr_hex(int nb);
void ft_putchar(char c);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        ft_putchar('\n');
        return 0;
    }
    int n = ft_atoi(argv[1]);
    ft_putnbr_hex(n);
    ft_putchar('\n');
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

void ft_putnbr_hex(int nb)
{
    long n = nb;
    char c;
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    char hex[] = "0123456789abcdef";
    if (n >= 16)
    {
        ft_putnbr_hex(n / 16);
    }
    c = hex[n % 16];
    ft_putchar(c);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}