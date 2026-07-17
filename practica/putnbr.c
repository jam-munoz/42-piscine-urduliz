#include <unistd.h>

void ft_putnbr(int nbr)
{
    char c;
    int sign = 1;

    if (nbr == -2147483647 - 1)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (nbr < 0)
    {
        sign = -1;
        nbr *= -1;
        write(1, "-", 1);
    }
    if (nbr >= 10)
    {
        ft_putnbr(nbr/10);
    }
    c = (nbr % 10) + '0';
    write(1, &c, 1);
    return;
}

int main(void)
{
    long long i = 4294967296;
    ft_putnbr(i);
    return 0;
}