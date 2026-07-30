/* Assignment name  : str_maxlenoc
Expected files   : str_maxlenoc.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes one or more strings and displays, followed by a
newline, the longest string that appears in every parameter. If more that one
string qualifies, it will display the one that appears first in the first
parameter. Note that the empty string technically appears in any string.

If there are no parameters, the program displays \n.

Examples:

$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
os
$>./str_maxlenoc | cat -e
$*/

#include <unistd.h>

int	ft_strlen(char *str);
void    ft_putchar(char c);

int ft_strstr(char *haystack, char *needle, int n)
{
    int success = 0;
    int i = 0;
    int k;
    while (haystack[i] && !success)
    {
        k = 0;
        success = 1;
        while (k <= n)
        {
            if (haystack[i] != needle[k])
            {
                success = 0;
                break;
            }
            k++;
            i++;
        }
        i++;
    }
    return success;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        ft_putchar('\n');
        return 0;
    }
    int maxlen = ft_strlen(argv[1]);
    int res_start = 1;
    int res_end = 0;
    int curr_start = 0;
    int curr_end;
    int success = 1;
    char *first_str = argv[1];
    int next_word;
    while (curr_start < maxlen)
    {
        success = 1;
        curr_end = curr_start;
        while (curr_end < maxlen && success)
        {
            success = 1;
            next_word = 2;
            while (next_word < argc && success)
            {
                if (!ft_strstr(argv[next_word], &first_str[curr_start], (curr_end - curr_start)))
                {
                    success = 0;
                    break;
                }
                next_word++;
            }
            if (!success)
                break;
            else if ((curr_end - curr_start) > (res_end - res_start))
            {
                res_end = curr_end;
                res_start = curr_start;
            }
            curr_end++;
        }
        curr_start++;
    }
    if ((res_end - res_start) >= 0)
        write(1, &(first_str[res_start]), (res_end - res_start + 1));
    ft_putchar('\n');
    return 0;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
