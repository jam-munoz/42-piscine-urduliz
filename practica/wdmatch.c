/* Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$*/

#include <unistd.h>
void	ft_putstr(char *str);
void    ft_putchar(char c);
int	ft_strlen(char *str);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        ft_putchar('\n');
        return 0;
    }
    char *str1 = argv[1];
    char *str2 = argv[2];
    int i = 0;
    int k = 0;
    int count = 0;
    int len = ft_strlen(str1);
    while (str1[i])
    {
        while(str2[k])
        {
            if (str1[i] == str2[k])
            {
                count++;
                k++;
                break;
            }
            else
                k++;
        }
        i++;
    }
    if (count == len)
        ft_putstr(str1);
    ft_putchar('\n');
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

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
