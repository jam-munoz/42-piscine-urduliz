/* Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$*/

#include <stdlib.h>
#include <stdio.h>

int ft_lcm(int a, int b);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("\n");
        return 0;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    if (x < 1 || y < 1)
    {
        printf("\n");
        return 0;
    }
    long lcm = ft_lcm(x, y);
    long gcd = (long)x * y / lcm;
    printf("%ld\n", gcd); 
}

int ft_lcm(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    int abase = a;
    int bbase = b;
    while (a != b)
    {
        if (a > b)
        {
            b = b + bbase;
        }
        else if (a < b)
        {
            a = a + abase;
        }
    }
    return a;
}