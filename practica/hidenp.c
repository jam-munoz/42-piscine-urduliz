/* Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>*/

#include <unistd.h>

void	ft_putstr(char *str);
void ft_putchar(char c);
int	ft_strlen(char *str);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        ft_putchar('\n');
        return 0;
    }
    int i = 0;
    int k = 0;
    int count = 0;
    int len = ft_strlen(argv[1]);
    while (argv[1][i])
    {
        while (argv[2][k])
        {
            if (argv[1][i] == argv[2][k])
            {
                k++;
                count++;
                break;
            }
            k++;
        }
        i++;
    }
    if (count == len)
        ft_putstr("1\n");
    else
        ft_putstr("0\n");
    return 0;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}