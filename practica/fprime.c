#include <stdio.h>
#include <stdlib.h>

/*int ft_is_prime(int n)
{
    if (n < 2)
        return 1;
    int i = 2;
    while (i < n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}*/

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 0;
    int i = 3;
    int n = atoi(argv[1]);
    int n2 = n;

    while (n >= i)
    {
        if (n % i == 0)
        {
            printf("%d", i);
            n /= i;
            i--;
            if (n > 1)
                printf("*");
        }
        i++;
    }
    if (n == n2)
        printf("%d", n);
    printf("\n");
}