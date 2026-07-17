#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int is_repeat[256] = {0};

    if (argc != 3)
        return 0;
    while (argv[1][i])
    {
        j = 0;
        while (argv[2][j])
        {
            if (argv[1][i] == argv[2][j])
            {
                if (is_repeat[(unsigned char)argv[1][i]] == 0)
                {
                    is_repeat[(unsigned char)argv[2][j]] = 1;
                    printf("%c", argv[2][j]);
                }
            }
            j++;
        }
        i++;
    }
    return 0;
}